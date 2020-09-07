import pygtk
import sys, Ice, IceStorm
Ice.loadSlice('../SLICE/SemanticModel.ice', ['-I', '/usr/share/slice'])
import SemanticModel

pygtk.require("2.0")
import gtk, gtk.glade
 
class GUI:
 
    def __init__(self):
        self.glade = gtk.glade.XML("presenceDummy.glade")
        self.glade.signal_autoconnect(self)
        self.glade.get_widget("window1").show_all()

    def on_window1_delete_event(self, widget, event):
        gtk.main_quit()
 
    def on_button1_clicked(self, widget):
        gtk.main_quit()
        Publisher().main(sys.argv)

class Publisher (Ice.Application):
    def run (self, argv):
        # Proxy al TopicManager.
        prx = self.communicator().stringToProxy('Events/TopicManager:tcp -p 10000')
        topicManagerPrx = IceStorm.TopicManagerPrx.checkedCast(prx)
        # Proxy al topic.
        try:
            topicPrx = topicManagerPrx.retrieve('alarms')
        except IceStorm.NoSuchTopic:
            topicPrx = topicManagerPrx.create('alarms')
        # Proxy al objeto que publica.
        pub = topicPrx.getPublisher()
        eventMonitorPrx = Events.EventMonitorPrx.uncheckedCast(pub)
        # Publicacion.
        e = Events.Event('tipo')
        eventMonitorPrx.report(e)
        return 0


g = GUI()
gtk.main()
