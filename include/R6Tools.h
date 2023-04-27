#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_R6Tools.h"
#include <QVector>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

class R6Tools : public QMainWindow
{
    Q_OBJECT

public:
    R6Tools(QWidget *parent = nullptr);
    ~R6Tools();

private:
    Ui::R6ToolsClass ui;
    QMap<int, QStringList> siteOptions;
    QStringList mapList;
    QVector<QString> BankSites;
    QVector<QString> BorderSites;
    QVector<QString> ChaletSites;
    QVector<QString> ClubhouseSites;
    QVector<QString> CoastlineSites;
    QVector<QString> ConsulateSites;
    QVector<QString> FavelaSites;
    QVector<QString> FortressSites;

    QVector<QVector<QString>> siteList;

    
    QString mapsPath;
    QString mapName;
    QString siteName;
    QDir baseDir;
    QStringList nameFilters;
    QList<QPixmap> images;
    QStringList imageNames;
    QFileInfoList fileInfoList;
    QPixmap bansPixmap;

    void loadMap(const QString& map);

private slots:
    void onFirstComboBoxIndexChanged(int index);
    void onSecondComboBoxIndexChanged(int index);


};
