#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent) {
    this->manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, &Worker::requestReceived);

    if ( pdfWriter.StartPDF("/home/tudor/Projects/final.pdf", ePDFVersion17) == eSuccess ) {
        qDebug()<<"Opened file";
    }

    PDFPage *page = new PDFPage();
    page->SetMediaBox(PDFRectangle(0,0,595,842));
    PageContentContext *contentContext = pdfWriter.StartPageContentContext(page);
    AbstractContentContext::TextOptions textOptions(font, 25, AbstractContentContext::eGray, 0);
    PDFUsedFont::TextMeasures textDimensions = font->CalculateTextDimensions("Barem BAC Fizica Electricitate", 25);
    contentContext->WriteText( (595-textDimensions.width) / 2, (842-textDimensions.height) / 2, "Barem BAC Fizica Electricitate", textOptions);
    pdfWriter.EndPageContentContext(contentContext);
    pdfWriter.WritePageAndRelease(page);

    addToPDF();
}

void Worker::addToPDF() {
    //Construct the URL
    QString url;
    QString urlSubiect;
    QString urlVarianta;

    if ( subiect == 1 ) {
        urlSubiect = "i";
    } else if ( subiect == 2 ) {
        urlSubiect = "ii";
    } else if ( subiect == 3 ) {
        urlSubiect = "iii";
    }

    if ( varianta / 10 == 0 ) {
        urlVarianta = "00" + QString::number(varianta);
    } else if ( varianta / 10 < 10 ) {
        urlVarianta = "0" + QString::number(varianta);
    } else  {
        urlVarianta = "100";
    }

    //Constructed the URL
    url = baseURL + urlSubiect + "_" + urlVarianta + ".pdf";

    //Make the request
    qDebug()<<"Requested file... "<<url;
    manager->get(QNetworkRequest(QUrl(url)));
}

void Worker::requestReceived(QNetworkReply *reply) {
    //Create info page
    QString title = "Varianta " + QString::number(varianta) + " Subiectul " + QString::number(subiect);

    PDFPage *page = new PDFPage();
    page->SetMediaBox(PDFRectangle(0,0,595,842));
    PageContentContext *contentContext = pdfWriter.StartPageContentContext(page);
    AbstractContentContext::TextOptions textOptions(font, 30, AbstractContentContext::eGray, 0);
    PDFUsedFont::TextMeasures textDimensions = font->CalculateTextDimensions(title.toStdString(), 30);
    contentContext->WriteText( (595-textDimensions.width) / 2, (842-textDimensions.height) / 2, title.toStdString(), textOptions);
    pdfWriter.EndPageContentContext(contentContext);
    pdfWriter.WritePageAndRelease(page);

    //Add the pdf from the interwebz to my pdf
    QSaveFile file("/home/tudor/Projects/inter.pdf");
    file.open(QIODevice::WriteOnly);
    file.write(reply->readAll());
    file.commit();

    pdfWriter.AppendPDFPagesFromPDF("/home/tudor/Projects/inter.pdf", PDFPageRange());

    //Get next pdf
    subiect++;
    if ( subiect == 4 ) {
        subiect = 2;
        varianta++;
    }

    if ( varianta == 101 ) {
        //stop
        pdfWriter.EndPDF();
        qDebug()<<"Done!";
    } else {
            addToPDF();
    }

    reply->deleteLater();
}
