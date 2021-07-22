<<<<<<< HEAD:src/qt/digibyteamountfield.cpp
// Copyright (c) 2011-2018 The DigiByte Core developers
=======
// Copyright (c) 2011-2020 The DigiByte Core developers
>>>>>>> bitcoin/8.22.0:src/qt/bitcoinamountfield.cpp
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/digibyteamountfield.h>

#include <qt/digibyteunits.h>
#include <qt/guiconstants.h>
#include <qt/guiutil.h>
#include <qt/qvaluecombobox.h>

#include <QApplication>
#include <QAbstractSpinBox>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLineEdit>

/** QSpinBox that uses fixed-point numbers internally and uses our own
 * formatting/parsing functions.
 */
class AmountSpinBox: public QAbstractSpinBox
{
    Q_OBJECT

public:
    explicit AmountSpinBox(QWidget *parent):
<<<<<<< HEAD:src/qt/digibyteamountfield.cpp
        QAbstractSpinBox(parent),
        currentUnit(DigiByteUnits::DGB),
        singleStep(100000) // satoshis
=======
        QAbstractSpinBox(parent)
>>>>>>> bitcoin/8.22.0:src/qt/bitcoinamountfield.cpp
    {
        setAlignment(Qt::AlignRight);

        connect(lineEdit(), &QLineEdit::textEdited, this, &AmountSpinBox::valueChanged);
    }

    QValidator::State validate(QString &text, int &pos) const override
    {
        if(text.isEmpty())
            return QValidator::Intermediate;
        bool valid = false;
        parse(text, &valid);
        /* Make sure we return Intermediate so that fixup() is called on defocus */
        return valid ? QValidator::Intermediate : QValidator::Invalid;
    }

    void fixup(QString &input) const override
    {
<<<<<<< HEAD:src/qt/digibyteamountfield.cpp
        bool valid = false;
        CAmount val = parse(input, &valid);
        if(valid)
        {
            input = DigiByteUnits::format(currentUnit, val, false, DigiByteUnits::separatorAlways);
=======
        bool valid;
        CAmount val;

        if (input.isEmpty() && !m_allow_empty) {
            valid = true;
            val = m_min_amount;
        } else {
            valid = false;
            val = parse(input, &valid);
        }

        if (valid) {
            val = qBound(m_min_amount, val, m_max_amount);
            input = DigiByteUnits::format(currentUnit, val, false, DigiByteUnits::SeparatorStyle::ALWAYS);
>>>>>>> bitcoin/8.22.0:src/qt/bitcoinamountfield.cpp
            lineEdit()->setText(input);
        }
    }

    CAmount value(bool *valid_out=nullptr) const
    {
        return parse(text(), valid_out);
    }

    void setValue(const CAmount& value)
    {
<<<<<<< HEAD:src/qt/digibyteamountfield.cpp
        lineEdit()->setText(DigiByteUnits::format(currentUnit, value, false, DigiByteUnits::separatorAlways));
=======
        lineEdit()->setText(DigiByteUnits::format(currentUnit, value, false, DigiByteUnits::SeparatorStyle::ALWAYS));
>>>>>>> bitcoin/8.22.0:src/qt/bitcoinamountfield.cpp
        Q_EMIT valueChanged();
    }

    void SetAllowEmpty(bool allow)
    {
        m_allow_empty = allow;
    }

    void SetMinValue(const CAmount& value)
    {
        m_min_amount = value;
    }

    void SetMaxValue(const CAmount& value)
    {
        m_max_amount = value;
    }

    void stepBy(int steps) override
    {
        bool valid = false;
        CAmount val = value(&valid);
        val = val + steps * singleStep;
<<<<<<< HEAD:src/qt/digibyteamountfield.cpp
        val = qMin(qMax(val, CAmount(0)), DigiByteUnits::maxMoney());
=======
        val = qBound(m_min_amount, val, m_max_amount);
>>>>>>> bitcoin/8.22.0:src/qt/bitcoinamountfield.cpp
        setValue(val);
    }

    void setDisplayUnit(int unit)
    {
        bool valid = false;
        CAmount val = value(&valid);

        currentUnit = unit;
        lineEdit()->setPlaceholderText(DigiByteUnits::format(currentUnit, m_min_amount, false, DigiByteUnits::SeparatorStyle::ALWAYS));
        if(valid)
            setValue(val);
        else
            clear();
    }

    void setSingleStep(const CAmount& step)
    {
        singleStep = step;
    }

    QSize minimumSizeHint() const override
    {
        if(cachedMinimumSizeHint.isEmpty())
        {
            ensurePolished();

            const QFontMetrics fm(fontMetrics());
            int h = lineEdit()->minimumSizeHint().height();
<<<<<<< HEAD:src/qt/digibyteamountfield.cpp
            int w = fm.width(DigiByteUnits::format(DigiByteUnits::DGB, DigiByteUnits::maxMoney(), false, DigiByteUnits::separatorAlways));
=======
            int w = GUIUtil::TextWidth(fm, DigiByteUnits::format(DigiByteUnits::DGB, DigiByteUnits::maxMoney(), false, DigiByteUnits::SeparatorStyle::ALWAYS));
>>>>>>> bitcoin/8.22.0:src/qt/bitcoinamountfield.cpp
            w += 2; // cursor blinking space

            QStyleOptionSpinBox opt;
            initStyleOption(&opt);
            QSize hint(w, h);
            QSize extra(35, 6);
            opt.rect.setSize(hint + extra);
            extra += hint - style()->subControlRect(QStyle::CC_SpinBox, &opt,
                                                    QStyle::SC_SpinBoxEditField, this).size();
            // get closer to final result by repeating the calculation
            opt.rect.setSize(hint + extra);
            extra += hint - style()->subControlRect(QStyle::CC_SpinBox, &opt,
                                                    QStyle::SC_SpinBoxEditField, this).size();
            hint += extra;
            hint.setHeight(h);

            opt.rect = rect();

            cachedMinimumSizeHint = style()->sizeFromContents(QStyle::CT_SpinBox, &opt, hint, this)
                                    .expandedTo(QApplication::globalStrut());
        }
        return cachedMinimumSizeHint;
    }

private:
    int currentUnit{DigiByteUnits::DGB};
    CAmount singleStep{CAmount(100000)}; // satoshis
    mutable QSize cachedMinimumSizeHint;
    bool m_allow_empty{true};
    CAmount m_min_amount{CAmount(0)};
    CAmount m_max_amount{DigiByteUnits::maxMoney()};

    /**
     * Parse a string into a number of base monetary units and
     * return validity.
     * @note Must return 0 if !valid.
     */
    CAmount parse(const QString &text, bool *valid_out=nullptr) const
    {
        CAmount val = 0;
        bool valid = DigiByteUnits::parse(currentUnit, text, &val);
        if(valid)
        {
            if(val < 0 || val > DigiByteUnits::maxMoney())
                valid = false;
        }
        if(valid_out)
            *valid_out = valid;
        return valid ? val : 0;
    }

protected:
    bool event(QEvent *event) override
    {
        if (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent->key() == Qt::Key_Comma)
            {
                // Translate a comma into a period
                QKeyEvent periodKeyEvent(event->type(), Qt::Key_Period, keyEvent->modifiers(), ".", keyEvent->isAutoRepeat(), keyEvent->count());
                return QAbstractSpinBox::event(&periodKeyEvent);
            }
        }
        return QAbstractSpinBox::event(event);
    }

    StepEnabled stepEnabled() const override
    {
        if (isReadOnly()) // Disable steps when AmountSpinBox is read-only
            return StepNone;
        if (text().isEmpty()) // Allow step-up with empty field
            return StepUpEnabled;

        StepEnabled rv = StepNone;
        bool valid = false;
        CAmount val = value(&valid);
        if (valid) {
            if (val > m_min_amount)
                rv |= StepDownEnabled;
<<<<<<< HEAD:src/qt/digibyteamountfield.cpp
            if(val < DigiByteUnits::maxMoney())
=======
            if (val < m_max_amount)
>>>>>>> bitcoin/8.22.0:src/qt/bitcoinamountfield.cpp
                rv |= StepUpEnabled;
        }
        return rv;
    }

Q_SIGNALS:
    void valueChanged();
};

#include <qt/digibyteamountfield.moc>

DigiByteAmountField::DigiByteAmountField(QWidget *parent) :
    QWidget(parent),
    amount(nullptr)
{
    amount = new AmountSpinBox(this);
    amount->setLocale(QLocale::c());
    amount->installEventFilter(this);
    amount->setMaximumWidth(240);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(amount);
    unit = new QValueComboBox(this);
    unit->setModel(new DigiByteUnits(this));
    layout->addWidget(unit);
    layout->addStretch(1);
    layout->setContentsMargins(0,0,0,0);

    setLayout(layout);

    setFocusPolicy(Qt::TabFocus);
    setFocusProxy(amount);

    // If one if the widgets changes, the combined content changes as well
    connect(amount, &AmountSpinBox::valueChanged, this, &DigiByteAmountField::valueChanged);
    connect(unit, qOverload<int>(&QComboBox::currentIndexChanged), this, &DigiByteAmountField::unitChanged);

    // Set default based on configuration
    unitChanged(unit->currentIndex());
}

void DigiByteAmountField::clear()
{
    amount->clear();
    unit->setCurrentIndex(0);
}

void DigiByteAmountField::setEnabled(bool fEnabled)
{
    amount->setEnabled(fEnabled);
    unit->setEnabled(fEnabled);
}

bool DigiByteAmountField::validate()
{
    bool valid = false;
    value(&valid);
    setValid(valid);
    return valid;
}

void DigiByteAmountField::setValid(bool valid)
{
    if (valid)
        amount->setStyleSheet("");
    else
        amount->setStyleSheet(STYLE_INVALID);
}

bool DigiByteAmountField::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
        // Clear invalid flag on focus
        setValid(true);
    }
    return QWidget::eventFilter(object, event);
}

QWidget *DigiByteAmountField::setupTabChain(QWidget *prev)
{
    QWidget::setTabOrder(prev, amount);
    QWidget::setTabOrder(amount, unit);
    return unit;
}

CAmount DigiByteAmountField::value(bool *valid_out) const
{
    return amount->value(valid_out);
}

void DigiByteAmountField::setValue(const CAmount& value)
{
    amount->setValue(value);
}

<<<<<<< HEAD:src/qt/digibyteamountfield.cpp
=======
void DigiByteAmountField::SetAllowEmpty(bool allow)
{
    amount->SetAllowEmpty(allow);
}

void DigiByteAmountField::SetMinValue(const CAmount& value)
{
    amount->SetMinValue(value);
}

void DigiByteAmountField::SetMaxValue(const CAmount& value)
{
    amount->SetMaxValue(value);
}

>>>>>>> bitcoin/8.22.0:src/qt/bitcoinamountfield.cpp
void DigiByteAmountField::setReadOnly(bool fReadOnly)
{
    amount->setReadOnly(fReadOnly);
}

void DigiByteAmountField::unitChanged(int idx)
{
    // Use description tooltip for current unit for the combobox
    unit->setToolTip(unit->itemData(idx, Qt::ToolTipRole).toString());

    // Determine new unit ID
    int newUnit = unit->itemData(idx, DigiByteUnits::UnitRole).toInt();

    amount->setDisplayUnit(newUnit);
}

void DigiByteAmountField::setDisplayUnit(int newUnit)
{
    unit->setValue(newUnit);
}

void DigiByteAmountField::setSingleStep(const CAmount& step)
{
    amount->setSingleStep(step);
}
