/*
 * © Copyright 2013-2017 Flo-Art.fr
 *
 * QRecipeWriter is available under the Creative Common BY-NC-SA licence.
 * All modifications and redistributions on the code are allowed for a NON COMMERCIAL usage.
 * Also, modifications and reproductions of the code must agree these conditions:
 *    - This copyright header must NOT be deleted.
 *    - You MUST redistribute the modified or not version under the Creative Common licence at least as restrictive as ours.
 *    - Flo-Art.fr can't be responsible for any version modified or redistributed by third parties.
 *    - Any commercial usage of this code, full or partial, is forbidden.
 *
 * QRecipeWriter est fournit sous la licence Creative Common BY-NC-SA.
 * Toutes les modifications et la redistribution sont autorisés pour une utilisation NON COMMERCIALE.
 * Par ailleurs, les modifications et la reproduction doivent respecter les règles ci-dessous :
 *    - Cette en-tête doit être maintenue.
 *    - Vous devez redistribuer la version modifiée ou non sous licence Creative Common au moins autant
 *      restrictive.
 *    - Flo-Art.fr ne peut être tenu pour responsable des versions modifiées et/ou redistribuées.
 *    - Toute utilisation commerciale partielle ou complète est interdite.
 */

#ifndef OPENDISTANT_H
#define OPENDISTANT_H

#include "filedownloader.h"
#include "httprequestworker.h"
#include "login.h"

#include <QCheckBox>
#include <QDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QMessageBox>
#include <QModelIndex>
#include <QRegExp>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QVariantMap>
#include <QVariantList>

namespace Ui {
class OpenDistant;
}

class OpenDistant : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDistant(QWidget *parent = 0);
    ~OpenDistant();
    void init();
    int idRecipeToOpen;
    int config;
    QString user, passwd;

private slots:
    void on_search_textChanged(const QString &arg1);
    void stateChanged();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_listRecipes_doubleClicked();

    void on_pushButton_clicked();

    void handle_result(HttpRequestWorker* worker);

private:
    Ui::OpenDistant *ui;
    QWidget *parentWidget;
    QStringList items;
    QMap<QString,QMap<QString,QVariant> > recipes;
    QMap<QString, QStringList > recipesByCats;
    void updateNbRecipes(int nbRecipes);
    QList<QCheckBox*> cboxes;
    void open(int config, QString typeServer);
    void addRecipe(QVariantMap recipe);
    void refreshRecipesList();
    QDialog *openInProgress;
};

#endif // OPENDISTANT_H
