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
}

QtWidgetsDebugMenu::~QtWidgetsDebugMenu()
{}

