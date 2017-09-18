#include "servercontrolpage.h"

#include <QDebug>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

ServerControlPage::ServerControlPage(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vlytMLyt = new QVBoxLayout();

    QHBoxLayout *hlytSpnbx = new QHBoxLayout();

    QLabel *lblPort = new QLabel(this);
    lblPort->setText(tr("Port:"));

    spnbxPort = new QSpinBox(this);
    spnbxPort->setRange(2,4096);
    spnbxPort->setValue(2000);

    QLabel *lblMax = new QLabel(this);
    lblMax->setText(tr("Max:"));

    spnbxMax = new QSpinBox(this);
    spnbxMax->setRange(1,20000);
    spnbxMax->setValue(8000);

    QLabel *lblIdle = new QLabel(this);
    lblIdle->setText(tr("Timeout:"));

    spnbxIdle = new QSpinBox(this);
    spnbxIdle->setRange(5,10000);
    spnbxIdle->setValue(30);

    hlytSpnbx->addWidget(lblPort);
    hlytSpnbx->addWidget(spnbxPort);
    hlytSpnbx->addWidget(lblMax);
    hlytSpnbx->addWidget(spnbxMax);
    hlytSpnbx->addWidget(lblIdle);
    hlytSpnbx->addWidget(spnbxIdle);

    QHBoxLayout *hlytBtn = new QHBoxLayout();

    btnStart = new QPushButton(this);
    btnStart->setText(tr("Start"));
    connect(btnStart,SIGNAL(pressed()),this,SLOT(on_btnStart_clicked()));
    connect(btnStart,SIGNAL(pressed()),this,SLOT(on_btnStart_clicked()));

    btnStop = new QPushButton(this);
    btnStop->setText(tr("Stop"));
    btnStop->setEnabled(false);
    connect(btnStop,SIGNAL(pressed()),this,SLOT(on_btnStop_clicked()));

    hlytBtn->addStretch(1);
    hlytBtn->addWidget(btnStart);
    hlytBtn->addWidget(btnStop);

    vlytMLyt->addLayout(hlytSpnbx);
    vlytMLyt->addLayout(hlytBtn);

    this->setLayout(vlytMLyt);
}

ServerControlPage::on_btnStart_clicked()
{
    setStarted(true);
}

ServerControlPage::on_btnStop_clicked()
{
    setStarted(false);
}

void ServerControlPage::setStarted(bool started)
{
    if(started)
    {
        btnStart->setEnabled(false);
        spnbxIdle->setEnabled(false);
        spnbxMax->setEnabled(false);
        spnbxPort->setEnabled(false);
        btnStop->setEnabled(true);
    }
    else
    {
        btnStart->setEnabled(true);
        spnbxIdle->setEnabled(true);
        spnbxMax->setEnabled(true);
        spnbxPort->setEnabled(true);
        btnStop->setEnabled(false);
    }
}
