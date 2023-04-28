#include "R6Tools.h"
#include <QComboBox>


R6Tools::R6Tools(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.map_combo, SIGNAL(currentIndexChanged(int)), this, SLOT(onFirstComboBoxIndexChanged(int)));
    connect(ui.site_combo, SIGNAL(currentIndexChanged(int)), this, SLOT(onSecondComboBoxIndexChanged(int)));
    onFirstComboBoxIndexChanged(ui.map_combo->currentIndex());
    onSecondComboBoxIndexChanged(ui.site_combo->currentIndex());

    mapList = { "Bank", "Border", "Chalet", "Clubhouse", "Coastline", "Consulate", "Favela", "Kafe Dostoyevsky", "Kanal", "Oregon", "Outback", "Skyscraper", "Theme Park", "Villa" };

    for (const QString& option : mapList) {
        ui.map_combo->addItem(option);
    }

    mapsPath= "maps";
    baseDir = QDir(mapsPath);
    nameFilters << "*site.png" << "*bans.png";
    QFileInfoList fileInfoList = baseDir.entryInfoList(nameFilters, QDir::Files);


    for (const QString& mapName : mapList) {
        baseDir.mkpath(mapName);
    }

}


void R6Tools::onFirstComboBoxIndexChanged(int index)
{
    // Clear the second QComboBox
    ui.site_combo->clear();

    imageNames.clear();
    images.clear();

    QString mapName = ui.map_combo->itemText(index);

    qDebug() <<"Loading this map: " << mapName;
    loadMap(mapName);

    // Add items to the second QComboBox based on the selected index in the first QComboBox
    ui.site_combo->addItems(imageNames);


}

void R6Tools::loadMap(const QString& map)
{
    QDir mapDir(baseDir.filePath(map)); // Access the map folder inside the baseDir folder
    QFileInfoList fileInfoList = mapDir.entryInfoList(nameFilters, QDir::Files);

    for (const QFileInfo& fileInfo : fileInfoList) {


        QString fileName = fileInfo.fileName();
        if (fileName.contains("_site")) {
            QString modifiedName = fileName.replace("_site.png", "");
            imageNames.append(modifiedName);
            QPixmap pixmap(fileInfo.filePath());
            images.append(pixmap);
		}

        // Check if the file name contains '_bans', and if so, set the pixmap to the banLabel
        if (fileName.contains("_bans")) {
            QPixmap pixmapBan(fileInfo.filePath());
            ui.banLabel->setPixmap(pixmapBan.scaled(ui.banLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }

    qDebug() << "Loaded " << imageNames.size() << " images";
    qDebug() << "imageNames" << imageNames;
}

void R6Tools::onSecondComboBoxIndexChanged(int index)
{
    // Get the selected item from the second QComboBox (site_combo)
    QString selectedImage = ui.site_combo->itemText(index);

    qDebug() << "Selected site: " << selectedImage;

    // Check if the selected image is not empty
    if (!selectedImage.isEmpty()) {

        // Find the index of the selected image in the imageNames list
        int imageIndex = imageNames.indexOf(selectedImage);
        qDebug() << "Image index: " << imageIndex;
        // If the index is valid, set the corresponding pixmap to the setupLabel
        if (imageIndex >= 0 && imageIndex < images.size()) {
            QPixmap pixmap = images[imageIndex];
            ui.setupLabel->setPixmap(pixmap.scaled(ui.setupLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }
}


R6Tools::~R6Tools()
{}
