<<<<<<< HEAD
// Copyright (c) 2011-2014 The DigiByte Core developers
=======
// Copyright (c) 2011-2020 The DigiByte Core developers
>>>>>>> bitcoin/8.22.0
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DIGIBYTE_QT_COINCONTROLTREEWIDGET_H
#define DIGIBYTE_QT_COINCONTROLTREEWIDGET_H

#include <QKeyEvent>
#include <QTreeWidget>

class CoinControlTreeWidget : public QTreeWidget
{
    Q_OBJECT

public:
    explicit CoinControlTreeWidget(QWidget *parent = nullptr);

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // DIGIBYTE_QT_COINCONTROLTREEWIDGET_H
