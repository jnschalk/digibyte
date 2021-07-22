<<<<<<< HEAD
// Copyright (c) 2011-2017 The DigiByte Core developers
=======
// Copyright (c) 2011-2020 The DigiByte Core developers
>>>>>>> bitcoin/8.22.0
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DIGIBYTE_QT_WALLETFRAME_H
#define DIGIBYTE_QT_WALLETFRAME_H

#include <QFrame>
#include <QMap>

<<<<<<< HEAD
class DigiByteGUI;
=======
>>>>>>> bitcoin/8.22.0
class ClientModel;
class PlatformStyle;
class SendCoinsRecipient;
class WalletModel;
class WalletView;

QT_BEGIN_NAMESPACE
class QStackedWidget;
QT_END_NAMESPACE

/**
 * A container for embedding all wallet-related
 * controls into DigiByteGUI. The purpose of this class is to allow future
 * refinements of the wallet controls with minimal need for further
 * modifications to DigiByteGUI, thus greatly simplifying merges while
 * reducing the risk of breaking top-level stuff.
 */
class WalletFrame : public QFrame
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit WalletFrame(const PlatformStyle *platformStyle, DigiByteGUI *_gui = 0);
=======
    explicit WalletFrame(const PlatformStyle* platformStyle, QWidget* parent);
>>>>>>> bitcoin/8.22.0
    ~WalletFrame();

    void setClientModel(ClientModel *clientModel);

    bool addWallet(WalletModel* walletModel, WalletView* walletView);
    void setCurrentWallet(WalletModel* wallet_model);
    void removeWallet(WalletModel* wallet_model);
    void removeAllWallets();

    bool handlePaymentRequest(const SendCoinsRecipient& recipient);

    void showOutOfSyncWarning(bool fShow);

    QSize sizeHint() const override { return m_size_hint; }

Q_SIGNALS:
    void createWalletButtonClicked();

private:
    QStackedWidget *walletStack;
<<<<<<< HEAD
    DigiByteGUI *gui;
=======
>>>>>>> bitcoin/8.22.0
    ClientModel *clientModel;
    QMap<WalletModel*, WalletView*> mapWalletViews;

    bool bOutOfSync;

    const PlatformStyle *platformStyle;

    const QSize m_size_hint;

public:
    WalletView* currentWalletView() const;
    WalletModel* currentWalletModel() const;

public Q_SLOTS:
    /** Switch to overview (home) page */
    void gotoOverviewPage();
    /** Switch to history (transactions) page */
    void gotoHistoryPage();
    /** Switch to receive coins page */
    void gotoReceiveCoinsPage();
    /** Switch to send coins page */
    void gotoSendCoinsPage(QString addr = "");

    /** Show Sign/Verify Message dialog and switch to sign message tab */
    void gotoSignMessageTab(QString addr = "");
    /** Show Sign/Verify Message dialog and switch to verify message tab */
    void gotoVerifyMessageTab(QString addr = "");

    /** Load Partially Signed DigiByte Transaction */
    void gotoLoadPSBT(bool from_clipboard = false);

    /** Encrypt the wallet */
    void encryptWallet();
    /** Backup the wallet */
    void backupWallet();
    /** Change encrypted wallet passphrase */
    void changePassphrase();
    /** Ask for passphrase to unlock wallet temporarily */
    void unlockWallet();

    /** Show used sending addresses */
    void usedSendingAddresses();
    /** Show used receiving addresses */
    void usedReceivingAddresses();
};

#endif // DIGIBYTE_QT_WALLETFRAME_H
