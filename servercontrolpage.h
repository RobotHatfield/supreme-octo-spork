#ifndef SERVERCONTROLPAGE_H
#define SERVERCONTROLPAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
class QSpinBox;
QT_END_NAMESPACE

class ServerControlPage : public QWidget
{
    Q_OBJECT
public:
    explicit ServerControlPage(QWidget *parent = nullptr);

signals:

public slots:
    on_btnStart_clicked();
    on_btnStop_clicked();

private:
    void setStarted(bool started);

    QSpinBox *spnbxPort;
    QSpinBox *spnbxMax;
    QSpinBox *spnbxIdle;
    QPushButton *btnStart;
    QPushButton *btnStop;
};

#endif // SERVERCONTROLPAGE_H
