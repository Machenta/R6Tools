#include "R6Tools.h"
#include <QComboBox>

R6Tools::R6Tools(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    mapList = { "Bank", "Border", "Chalet", "Clubhouse", "Coastline", "Consulate", "Favela", "Fortress", "Hereford Base", "House", "Kafe Dostoyevsky", "Kanal", "Oregon", "Outback", "Presidential Plane", "Skyscraper", "Theme Park", "Tower", "Villa", "Yacht" };
    BankSites = { "Archives/Tellers", "CEO Office/Staff Room", "Open Area/Kitchen", "Staff Room/CEO Office", "Tellers/Archives" };
    BorderSites = { "Armory/Archives", "Bathroom/Tellers", "Customs/Supply Room", "Ventilation/Workshop", "Workshop/Ventilation" };
    ChaletSites = { "Bar/Gaming Room", "Dining Room/Kitchen", "Kitchen/Dining Room", "Library/Living Room", "Living Room/Library" };
    ClubhouseSites = { "Bar/Stock Room", "CCTV/Cash Room", "Church/Arsenal Room", "Gym/Bedroom", "Master Bedroom/Gym" };
    CoastlineSites = { "Blue Bar/Sunrise Bar", "Hookah Lounge/Billiards Room", "Kitchen/Service Entrance", "Penthouse/Theater", "Theater/Penthouse" };
    ConsulateSites = { "Consul Office/Meeting Room", "Garage/Cafeteria", "Lobby/Press Room", "Meeting Room/Consul Office", "Press Room/Lobby" };
    FavelaSites = { "Aunt's Apartment/Armory Room", "Biker's Apartment/Grow Room", "Football Apartment/Workshop", "Packaging Room/Back Stairs", "Showers/Toilet" };
    FortressSites = { "Armory/Throne Room", "Bathroom/Bedroom", "Commanders Office/Dormitory", "Great Hall/Dining Room", "Throne Room/Armory" };
    siteList = { BankSites, BorderSites, ChaletSites, ClubhouseSites, CoastlineSites, ConsulateSites, FavelaSites };
        
    for (const QString& option : mapList) {
        ui.map_combo->addItem(option);
    }



}


void R6Tools::onFirstComboBoxIndexChanged(int index)
{
    // Clear the second QComboBox
    ui.site_combo->clear();

    // Add items to the second QComboBox based on the selected index in the first QComboBox
    if (index == 0) {
        QStringList options = { "Site 1-1", "Site 1-2", "Site 1-3" };
        ui.site_combo->addItems(options);
    }
    else if (index == 1) {
        QStringList options = { "Site 2-1", "Site 2-2", "Site 2-3" };
        ui.site_combo->addItems(options);
    }
    // Add more conditions for other indices as needed
}



R6Tools::~R6Tools()
{}
