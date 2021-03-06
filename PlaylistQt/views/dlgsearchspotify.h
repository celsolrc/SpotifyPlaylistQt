#ifndef DLGSEARCHSPOTIFY_H
#define DLGSEARCHSPOTIFY_H

#include <QDialog>

#include "../controllers/spotifycontroller.h"
#include "../controllers/localinfocontroller.h"
#include "../controllers/playlistcontroller.h"

#include "../models/track.h"

namespace Ui {
class DlgSearchSpotify;
}

class DlgSearchSpotify : public QDialog
{
    Q_OBJECT

public:
    explicit DlgSearchSpotify(SpotifyController& spotifyController, PlaylistController& playlistController, QWidget *parent = nullptr);
    ~DlgSearchSpotify();


private slots:

    void on_pbClose_clicked();
    void on_pbInsert_clicked();
    void on_pbSearch_clicked();

    void searchError(QString errorMessage);
    void searchResult(QJsonObject searchResult);

private:
    Ui::DlgSearchSpotify *ui;

    QMap<QString, Track> tracks;

    SpotifyController& m_spotifyController;
    PlaylistController& m_playlistController;
};

#endif // DLGSEARCHSPOTIFY_H
