#include "playlistcontroller.h"

#include <QFile>
#include<QTextStream>

#include <qdebug.h>

PlaylistController::PlaylistController()
{
    setPlaylistName("noname");
}

void PlaylistController::fixExtensionFile()
{
    if (m_playListName.toLower().right(4).compare(D_FILEEXT_PLAYLIST) != 0)
        m_playListName += D_FILEEXT_PLAYLIST;
}

bool PlaylistController::loadPlaylist()
{
    bool result = false;
    QFile arquivo( m_playListName );

    m_playlist.clear();

    if (arquivo.open(QFile::ReadOnly|QFile::Text)){
        QTextStream entrada(&arquivo);

        QString versao = entrada.readLine();

        if (versao.compare(D_VERSION_PLAYLIST)==0)
        {
            QString lineMusic;

            while (entrada.status() == QTextStream::Status::Ok) {
                lineMusic = entrada.readLine();

                if (lineMusic.length()>0)
                    m_playlist.append(lineMusic);
            }

            arquivo.close();

            m_isLoad = true;
            m_isSaved = true;
            result = true;
        }
    }

    updateView();

    return result;
}

bool PlaylistController::savePlaylist()
{
    bool result = false;

    if (havePlayList()) {
        QFile arquivo( m_playListName );

        if (arquivo.open(QFile::WriteOnly|QFile::Text)){
            QTextStream saida(&arquivo);

            saida << D_VERSION_PLAYLIST;

            for ( const auto& musicLine : m_playlist  ) {
                saida << musicLine;
            }

            arquivo.flush();
            arquivo.close();

            m_isLoad = true;
            m_isSaved = true;
            result = true;
        }
    }

    return result;
}

void PlaylistController::updateView() {
    m_lwMusicsPlaylist->clear();

    m_lwMusicsPlaylist->addItems(m_playlist);
}
