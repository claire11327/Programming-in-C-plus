#include "gameover.h"

gameover::gameover()
{
    messageLabel = new QLabel(msg, (QWidget*)this);
        setLabelStyle(messageLabel, 14, 165);

        connect(button, SIGNAL(clicked(bool)), parent, SLOT(tryAgain()));

        show();
}
