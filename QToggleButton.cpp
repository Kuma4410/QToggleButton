#include "QToggleButton.h"
#include <qboxlayout.h>
#include <qevent.h>
#include <qfontmetrics.h>
#include <qlabel.h>
#include <qpainter.h>
#include <qslider.h>

QToggleButton::QToggleButton(QWidget *parent /* = nullptr */)
    : QCheckBox(parent)
    //, _icon(new QLabel(this))
    //, _label(new QLabel(this))
    //, _slider(new QSlider(this))
    //, _sliderSize(QSize())
    //, _sliderLayout(NearText)
{
    //QHBoxLayout *layout = new QHBoxLayout(this);
    //layout->addWidget(_icon);
    //layout->addWidget(_label);
    //layout->addWidget(_slider);
    //layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding));
    //setLayout(layout);
    //_slider->setMinimum(0);
    //_slider->setMaximum(1);
    //_slider->setSingleStep(1);
    //_slider->setOrientation(Qt::Horizontal);
    //connect(this, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));
    //connect(_slider, SIGNAL(valueChanged(int)), this, SLOT(onSliderValueChanged(int)));
}

QToggleButton::~QToggleButton()
{
}

/*
void QToggleButton::setIcon(const QIcon &icon)
{
    QCheckBox::setIcon(icon);
    QSize size = iconSize();
    QPixmap pixmap = icon.pixmap(size);
    _icon->setPixmap(pixmap);
}
*/

void QToggleButton::setText(const QString &text)
{
    QCheckBox::setText(text);
    //_label->setText(text);
}

void QToggleButton::setTristate(bool y)
{
    QCheckBox::setTristate(y);
    int max = y ? 2 : 1;
    _slider->setMaximum(max);
}

/*
void QToggleButton::paintEvent(QPaintEvent *event)
{
    const int deafultSliderWidth = 100;
    const int defaultSliderMargin = 50;

    QPainter painter(this);
    painter.save();

    // draw icon
    if (!icon().isNull())
    {
        QRect r = _icon->rect();
        QSize size = iconSize();
        QPixmap pixmap = icon().pixmap(iconSize());
        painter.drawPixmap(rect(), pixmap);
    }

    // draw text
    //QPalette palette = this->palette();
    //painter.setPen(palette.text().color());
    //QRect r = _label->rect();
    //painter.drawText(rect(), _label->text());

#if 0
    // get text size
    QFontMetrics metrics = fontMetrics();
    QSize textSize = metrics.size(Qt::TextSingleLine | Qt::TextShowMnemonic, text());

    // set slider size
    QSize sliderSize = _sliderSize.isValid() ? _sliderSize : QSize(deafultSliderWidth, height());

    // set slider position
    int totalWidth = textSize.width() + defaultSliderMargin + sliderSize.width();
    int sliderLeft = 0;
    switch (_sliderLayout)
    {
        case NearText:
        {
            sliderLeft = (totalWidth < width()) ? textSize.width() : (totalWidth - sliderSize.width());
            sliderLeft += defaultSliderMargin;
            break;
        }
        case FarText:
        {
            sliderLeft = width() - defaultSliderMargin - sliderSize.width();
            break;
        }
        default:
        {
            break;
        }
    }
    sliderLeft += defaultSliderMargin;
    _slider->setGeometry(sliderLeft, 0, 0, 0);
    _slider->setFixedSize(sliderSize);
#endif

    // set slider state
    int value = sliderValue(checkState());
    _slider->setValue(value);
}
*/

int QToggleButton::sliderValue(Qt::CheckState state) const
{
    int value = -1;
    switch (checkState())
    {
        case Qt::Unchecked:
        {
            value = 0;
            break;
        }
        case Qt::PartiallyChecked:
        {
            value = 1;
            break;
        }
        case Qt::Checked:
        {
            value = isTristate() ? 2 : 1;
            break;
        }
        default:
        {
            break;
        }
    }
    return value;
}

void QToggleButton::onSliderValueChanged(int value)
{
    switch (value)
    {
        case 0:
        {
            setCheckState(Qt::Unchecked);
            break;
        }
        case 1:
        {
            setCheckState(isTristate() ? Qt::PartiallyChecked : Qt::Checked);
            break;
        }
        case 2:
        {
            setCheckState(Qt::Checked);
            break;
        }
        default:
        {
            break;
        }
    }
}
