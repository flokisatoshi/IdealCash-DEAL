#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "clientmodel.h"

#include "version.h"

#include <QDesktopWidget>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    //adding android size code
            QFont font;
            font.setFamily(font.defaultFamily());
            QRect rec = QApplication::desktop()->screenGeometry();
            int fS=std::max(7,(int)rec.width()/80);
            font.setPointSize(fS);
            this->setFont(font);
            this->setFixedWidth((int)rec.width());
            this->setFixedHeight((int)(rec.height()*0.8));
}

void AboutDialog::setModel(ClientModel *model)
{
    if(model)
    {
        ui->versionLabel->setText(model->formatFullVersion());
    }
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_buttonBox_accepted()
{
    close();
}
