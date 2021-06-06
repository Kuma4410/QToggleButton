/**
 * @file QToggleButton.h
 * @brief Toggle button class
 * @author Yoshito Kumakura
 * @date 2021.06.05
 * @version 0.0
 * copyright All rights reserved.
 */

#ifndef QTOGGLEBUTTON_H
#define QTOGGLEBUTTON_H

#include <qcheckbox.h>

class QLabel;
class QSlider;

/**
 * @class QToggleButton
 * @brief Toggle button class
 */
class QToggleButton : public QCheckBox
{
    Q_OBJECT

public:
    /**
     * @enum SliderLayout
     * @brief Slider position near or far from text
     */
    enum SliderLayout
    {
        NearText,
        FarText,
    };

public:
    QToggleButton(QWidget *parent = nullptr);
    virtual ~QToggleButton();
    void setIcon(const QIcon &icon);
    void setSliderLayout(SliderLayout sliderLayout);
    void setText(const QString &text);
    void setTristate(bool y);

protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    void setSliderValue(Qt::CheckState state);
    int sliderValue(Qt::CheckState state) const;

private slots:
    void onSliderReleased();
    void onStateChanged(int state);

private:
    QLabel *_icon;                  ///< Icon
    QLabel *_label;                 ///< Text label
    QSlider *_slider;               ///< Toggle part
    SliderLayout _sliderLayout;     ///< Slider position near or far from text
};

#endif // QTOGGLEBUTTON_H
