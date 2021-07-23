// Copyright (c) 2009-2020 The Bitcoin Core developers
// Copyright (c) 2014-2020 The DigiByte Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/openuridialog.h>
#include <qt/forms/ui_openuridialog.h>

#include <qt/guiutil.h>
#include <qt/sendcoinsrecipient.h>

#include <QUrl>

OpenURIDialog::OpenURIDialog(QWidget *parent) :
    QDialog(parent, GUIUtil::dialog_flags),
    ui(new Ui::OpenURIDialog)
{
    ui->setupUi(this);
<<<<<<< HEAD
    ui->uriEdit->setPlaceholderText("digibyte:");
=======

    GUIUtil::handleCloseWindowShortcut(this);
>>>>>>> bitcoin/8.22.0
}

OpenURIDialog::~OpenURIDialog()
{
    delete ui;
}

QString OpenURIDialog::getURI()
{
    return ui->uriEdit->text();
}

void OpenURIDialog::accept()
{
    SendCoinsRecipient rcp;
    if(GUIUtil::parseDigiByteURI(getURI(), &rcp))
    {
        /* Only accept value URIs */
        QDialog::accept();
    } else {
        ui->uriEdit->setValid(false);
    }
}
<<<<<<< HEAD

void OpenURIDialog::on_selectFileButton_clicked()
{
    QString filename = GUIUtil::getOpenFileName(this, tr("Select payment request file to open"), "", "", nullptr);
    if(filename.isEmpty())
        return;
    QUrl fileUri = QUrl::fromLocalFile(filename);
    ui->uriEdit->setText("digibyte:?r=" + QUrl::toPercentEncoding(fileUri.toString()));
}
=======
>>>>>>> bitcoin/8.22.0
