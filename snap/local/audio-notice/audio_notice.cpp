// audio_notice.cpp - minimal QtWidgets dialog for the audacity snap.
//
// Shown by snap/command-chain/audio-plug-check (command-chain, runs before
// the app) when the snap has no audio access at all. Successor of the old
// alsa-mixin yad dialog, reborn as a native Qt dialog so no GTK stack is
// needed in the Qt6/kde-neon-6 runtime.
//
// Exit codes consumed by the chain script:
//   0   continue and ask next time
//   200 user says they connected the interfaces - re-test
//   201 continue and never ask again (script persists a marker)
//   202 quit - do not start the app

#include <QApplication>
#include <QMessageBox>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QApplication::setApplicationName("audacity-audio-notice");
    QApplication::setOrganizationName("Audacity");

    QMessageBox box;
    box.setIcon(QMessageBox::Warning);
    box.setWindowTitle("Audacity - audio access needed");
    box.setTextFormat(Qt::RichText);
    box.setText(
        "<b>Audacity has no access to your system's audio.</b><br><br>"
        "Without it, the app may start very slowly, appear frozen, and "
        "playback/recording will not work.<br><br>"
        "Grant access by running:<br>"
        "<tt>&nbsp;&nbsp;sudo snap connect audacity:pulseaudio</tt><br>"
        "<small>&nbsp;&nbsp;(most systems: enables playback and recording)</small><br><br>"
        "Optional, for direct access to ALSA hardware devices:<br>"
        "<tt>&nbsp;&nbsp;sudo snap connect audacity:alsa</tt>");

    QPushButton *retest = box.addButton("I've connected them - re-test",
                                        QMessageBox::ActionRole);
    QPushButton *ask = box.addButton("Continue and ask next time",
                                     QMessageBox::AcceptRole);
    QPushButton *never = box.addButton("Continue and don't ask again",
                                       QMessageBox::AcceptRole);
    QPushButton *quit = box.addButton("Quit", QMessageBox::RejectRole);
    Q_UNUSED(ask);
    box.setDefaultButton(never);

    box.exec();

    if (box.clickedButton() == retest)
        return 200;
    if (box.clickedButton() == never)
        return 201;
    if (box.clickedButton() == quit)
        return 202;
    return 0;
}
