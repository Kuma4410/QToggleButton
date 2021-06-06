#ifndef QTOGGLEBUTTON_H
#define QTOGGLEBUTTON_H

#include <qcheckbox.h>

class QLabel;
class QSlider;

class QToggleButton : public QCheckBox
{
    Q_OBJECT

public:
    enum SliderLayout
    {
        NearText,
        FarText,
    };

public:
    QToggleButton(QWidget *parent = nullptr);
    virtual ~QToggleButton();
    //void setIcon(const QIcon &icon);
    void setText(const QString &text);
    void setTristate(bool y);
    void setSliderSize(const QSize &size) { _sliderSize = size; }
    void setSliderLayout(SliderLayout layout) { _sliderLayout = layout; }

protected:
    //void paintEvent(QPaintEvent *event);

private:
    int sliderValue(Qt::CheckState state) const;

private slots:
    void onSliderValueChanged(int value);

private:
    QLabel *_icon;
    QLabel *_label;
    QSlider *_slider;
    QSize _sliderSize;
    SliderLayout _sliderLayout;
};

#endif // QTOGGLEBUTTON_H
