#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_R6Tools.h"
#include <QVector>

class R6Tools : public QMainWindow
{
    Q_OBJECT

public:
    R6Tools(QWidget *parent = nullptr);
    ~R6Tools();

private:
    Ui::R6ToolsClass ui;
    QVector<QString> mapList;
    QVector<QString> BankSites;
    QVector<QString> BorderSites;
    QVector<QString> ChaletSites;
    QVector<QString> ClubhouseSites;
    QVector<QString> CoastlineSites;
    QVector<QString> ConsulateSites;
    QVector<QString> FavelaSites;
    QVector<QString> FortressSites;

    QVector<QVector<QString>> siteList;


private slots:
    void onFirstComboBoxIndexChanged(int index);


};
