#include "QToggleButton.h"
#include "SampleWindow.h"
#include "ui_SampleWindow.h"

SampleWindow::SampleWindow(QWidget *parent /* = nullptr */)
    : QMainWindow(parent)
    , _ui(new Ui::SampleWindowClass)
{
    _ui->setupUi(this);
    _ui->toggleButton->setTristate(true);
    _ui->toggleButton->setCheckState(Qt::PartiallyChecked);
    _ui->toggleButton->setSliderLayout(QToggleButton::FarText);
    QString strStyle =
        "QToggleButton QSlider::groove:horizontal {"
        "border: 3px solid #666666;"
        "background-color: #CCCCCC;"
        "}"
        "QToggleButton QSlider::handle:horizontal {"
        "width: 10px;"
        "border: 3px solid #333333;"
        "background: #CCCCCC;"
        "}"
        "QToggleButton QSlider::sub-page:horizontal {"
        "background: green;"
        "}"
        "QToggleButton QSlider::add-page:horizontal {"
        "background: gray;"
        "}";
    setStyleSheet(strStyle);
}

SampleWindow::~SampleWindow()
{
    delete _ui;
}
