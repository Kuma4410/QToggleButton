/**
 * @file QToggleButton.cpp
 * @brief Toggle button class
 * @author Yoshito Kumakura
 * @date 2021.06.05
 * @version 0.0
 * copyright All rights reserved.
 */

#include "QToggleButton.h"
#include <qboxlayout.h>
#include <qlabel.h>
#include <qslider.h>

/**
 * @brief Constructor
 * @param[in] parent parent widget
 * @detail Create layout in checkbox
 */
QToggleButton::QToggleButton(QWidget *parent /* = nullptr */)
    : QCheckBox(parent)
    , _icon(new QLabel(this))
    , _label(new QLabel(this))
    , _slider(new QSlider(this))
    , _sliderLayout(NearText)
{
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->setMargin(0);
    hlayout->addWidget(_icon);
    hlayout->addWidget(_label);
    hlayout->addWidget(_slider, 0, Qt::AlignLeading);
    hlayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Preferred));
    setLayout(hlayout);
    _slider->setOrientation(Qt::Horizontal);
    _slider->setPageStep(0);
    connect(this, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));
    connect(_slider, SIGNAL(sliderReleased()), this, SLOT(onSliderReleased()));
}

/**
 * @brief Destructor
 */
QToggleButton::~QToggleButton()
{
}

/**
 * @brief Set icon
 * @param[in] icon icon
 * @detail Override QCheckBox setIcon()
 */
void QToggleButton::setIcon(const QIcon &icon)
{
    QCheckBox::setIcon(icon);
    _icon->setPixmap(icon.pixmap(iconSize()));
}

/**
 * @brief Set whether slider is near or far from text
 * @param[in] sliderLayout near or far from text
 * @detail Exchange spacer item
 */
void QToggleButton::setSliderLayout(SliderLayout sliderLayout)
{
    _sliderLayout = sliderLayout;

    // get spacer item
    QHBoxLayout *hlayout = qobject_cast< QHBoxLayout* >(layout());
    QLayoutItem *spacerItem = nullptr;
    for (int i = 0; i < hlayout->count(); i++)
    {
        if (dynamic_cast< QSpacerItem* >(hlayout->itemAt(i)))
        {
            spacerItem = layout()->takeAt(i);;
        }
    }

    // insert spacer item
    if (spacerItem)
    {
        switch (_sliderLayout)
        {
            case NearText:
            {
                hlayout->insertItem(3, spacerItem);
                break;
            }
            case FarText:
            default:
            {
                hlayout->insertItem(2, spacerItem);
                break;
            }
        }
    }
}

/**
 * @brief Set text
 * @param[in] text text
 * @detail Override QCheckBox setText()
 */
void QToggleButton::setText(const QString &text)
{
    QCheckBox::setText(text);
    _label->setText(text);
}

/**
 * @brief Set whether the checkbox has a tri-state
 * @param[in] y has tri state
 * @detail Override QCheckBox setTristate()
 */
void QToggleButton::setTristate(bool y)
{
    QCheckBox::setTristate(y);
    int max = y ? _slider->maximum() : (_slider->maximum() - _slider->minimum()) / 2;
    _slider->setMaximum(max);
}

/**
 * @brief Paint event
 * @detail Do NOT paint checkbox because toggle has another layout in constructor
 * @detail Override QCheckBox paintEvent()
 */
void QToggleButton::paintEvent(QPaintEvent *)
{
    //QCheckBox::paintEvent(event);
}

/**
 * @brief Set slider value
 * @param[in] state check state
 * @detail Slider value changed according to check state
 */
void QToggleButton::setSliderValue(Qt::CheckState state)
{
    int value = sliderValue(state);
    _slider->setValue(value);
}

/**
 * @brief Get slider value
 * @param[in] state check state
 * @return slider value
 */
int QToggleButton::sliderValue(Qt::CheckState state) const
{
    int value = -1;
    switch (checkState())
    {
        case Qt::Unchecked:
        {
            value = _slider->minimum();
            break;
        }
        case Qt::PartiallyChecked:
        {
            value = (_slider->maximum() - _slider->minimum()) / 2;
            break;
        }
        case Qt::Checked:
        {
            value = _slider->maximum();
            break;
        }
        default:
        {
            break;
        }
    }
    return value;
}

/**
 * @brief Slot event when slider is released
 * @detail Update check state and slider value
 */
void QToggleButton::onSliderReleased()
{
    // get current slider value
    int value = _slider->value();

    // judge check state from slider value
    int min = _slider->minimum();
    int max = _slider->maximum();
    int mid = (max - min) / 2;
    Qt::CheckState state;

    // slider value depends on tri state
    if (isTristate())
    {
        if (value < mid / 2)
        {
            state = Qt::Unchecked;
        }
        else if (value < mid * 3 / 2)
        {
            state = Qt::PartiallyChecked;
        }
        else
        {
            state = Qt::Checked;
        }
    }
    else
    {
        if (value < mid)
        {
            state = Qt::Unchecked;
        }
        else
        {
            state = Qt::Checked;
        }
    }

    // set check state and slider value
    setCheckState(state);
    setSliderValue(state);
}

/**
 * @brief Slot event when check state is changed
 * @param[in] state check state
 * @detail Set slider value according to check state
 */
void QToggleButton::onStateChanged(int state)
{
    setSliderValue(static_cast< Qt::CheckState >(state));
}
