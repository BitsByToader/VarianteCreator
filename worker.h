#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSaveFile>

#include <PDFWriter.h>
#include <PDFPage.h>
#include <AbstractContentContext.h>
#include <PageContentContext.h>
#include <PDFUsedFont.h>

class Worker : public QObject {
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    void addToPDF();

public slots:
    void requestReceived(QNetworkReply *reply);

private:
    //Network stuff...
    QNetworkAccessManager *manager = nullptr;

    //PDF stuff...
    PDFWriter pdfWriter;
    PDFUsedFont *font = pdfWriter.GetFontForFile("/home/tudor/.local/share/fonts/Arial.ttf");

    //Book-keeping
    qint8 varianta = 1;
    //Also change subiect to 1 when downloading the tests, and 2 for results
    qint8 subiect = 2;

    //Default values
    const QString baseURL = "https://variante-mate.ro/bacalaureat/R-ELECTRICITATE/e_f_prod_si_utiliz_crt_cont_rez_";
    //OTHER URLS:
    //  https://variante-mate.ro/bacalaureat/R-ELECTRICITATE/e_f_prod_si_utiliz_crt_cont_rez_
    //  https://variante-mate.ro/bacalaureat/R-TERMODINAMICA/e_f_termodinamica_rez_
    //  https://variante-mate.ro/bacalaureat/ELECTRICITATE/e_f_electricitate_s
    //  https://variante-mate.ro/bacalaureat/TERMODINAMICA/e_f_TERMODINAMICA_siii_053.pdf
};

#endif // WORKER_H
