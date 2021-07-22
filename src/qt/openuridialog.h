<<<<<<< HEAD
// Copyright (c) 2011-2015 The DigiByte Core developers
=======
// Copyright (c) 2011-2020 The DigiByte Core developers
>>>>>>> bitcoin/8.22.0
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DIGIBYTE_QT_OPENURIDIALOG_H
#define DIGIBYTE_QT_OPENURIDIALOG_H

#include <QDialog>

namespace Ui {
    class OpenURIDialog;
}

class OpenURIDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenURIDialog(QWidget *parent);
    ~OpenURIDialog();

    QString getURI();

protected Q_SLOTS:
    void accept() override;

private:
    Ui::OpenURIDialog *ui;
};

#endif // DIGIBYTE_QT_OPENURIDIALOG_H
