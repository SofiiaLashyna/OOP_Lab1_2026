#ifndef EDITPLANETDIALOG_H
#define EDITPLANETDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QCheckBox>
#include <RandomUtilities.h>

#include "Planet.h"

class EditPlanetDialog : public QDialog {
    Q_OBJECT

public:
    explicit EditPlanetDialog(Planet *planet, RandomGenerator *rng, QWidget *parent = nullptr);
    void saveChanges();

private:
    Planet *planet;
    RandomGenerator *rngPtr;
    QLineEdit *nameEdit;
    QComboBox *typeComboBox;
    QDoubleSpinBox *massSpinBox;
    QDoubleSpinBox *orbitRadiusSpinBox;
    QDoubleSpinBox *speedSpinBox;
    QDoubleSpinBox *inclinationSpinBox;
    QCheckBox *habitableCheckBox;
    QCheckBox *ringsCheckBox;
};

#endif // EDITPLANETDIALOG_H