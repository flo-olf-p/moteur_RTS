#include "QtWidgetsDebugMenu.h"

QtWidgetsDebugMenu::QtWidgetsDebugMenu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.Update, &QPushButton::clicked, this, [this]()
		{
			int newSize = ui.SizeCase->value();

			emit gridSizeChanged(newSize);
		});

	connect(ui.AddAnimal, &QPushButton::clicked, this, [this]()
		{
			int PredNumber = ui.PredNumber->value();
			int HerbNumber = ui.HerbNumber->value();


			emit addAnimalButton(PredNumber, HerbNumber);
		});
}

QtWidgetsDebugMenu::~QtWidgetsDebugMenu()
{}

