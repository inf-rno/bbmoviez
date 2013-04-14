// Navigation pane project template
import bb.cascades 1.0
import bb.system 1.0
import "pages" 1.0

NavigationPane {
    id: navigationPane
    
    attachedObjects: [
        ComponentDefinition {
            id: movieListPage
            source: "asset:///pages/MovieListPage.qml"
        },
        ComponentDefinition {
            id: movieDetailsPage
            source: "asset:///pages/MovieDetails.qml"
        }
    ]
    
    SearchPage{}
    onCreationCompleted: {
        // this slot is called when declarative scene is created
        // write post creation initialization here
        console.log("NavigationPane - onCreationCompleted()");

        // enable layout to adapt to the device rotation
        // don't forget to enable screen rotation in bar-bescriptor.xml (Application->Orientation->Auto-orient)
        OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
    }
}


// Tabbed Pane project template
/*import bb.cascades 1.0
import bb.system 1.0
import "controls" 1.0
import "pages" 1.0

TabbedPane {
    showTabsOnActionBar: true
    activeTab: searchTab
    id: tabPane
        
    Menu.definition: MenuDefinition {
        settingsAction: SettingsActionItem {
                onTriggered: {
                    settingsSheet.content.bindData();
                    settingsSheet.open();
                }
        } // it says this is an error, but it is actually correct
    }    
    Tab {
        title: qsTr("Search")
        imageSource: "asset:///images/navigation/updates.png"
        id: searchTab
        
        content: NavigationPane {
            id: updatesTabPane
            SearchPage {}
            onPopTransitionEnded: {
                //resetAddConnectionPageBookMark(page);
                page.destroy();
            }            
        }
    }
    Tab {
        title: qsTr("Movie Selection")
        imageSource: "asset:///images/navigation/you.png"
        id: youTab

        content: NavigationPane {
            You {}
            onPopTransitionEnded: {
                //resetAddConnectionPageBookMark(page);
                page.destroy();
            }            
        }
    }
    Tab {
        title: qsTr("Movie")
        imageSource: "asset:///images/navigation/messages.png"
        id: messagesTab

        content: NavigationPane {
            id: navPaneMessageID
            Messages { }
            onPopTransitionEnded: {
                resetAddConnectionPageBookMark(page);
                page.destroy();
            }            
        }
    }   
    
    onCreationCompleted:{
        Application.cover = appCover.createObject();
    }
    onActiveTabChanged: {      
    }
    onSidebarVisualStateChanged:{            
    }
                
                     
    /*function handleInvokedForShare(shareConent){       
        shareUpdateSheet.shareInvoked(true);                                       
        shareUpdateSheet.open();    
    }    
    
    function handleInvokedForProfile(profileUrl){
        
        var detailsPage = connectionDetailsPage.createObject();
        activeTab.content.push(detailsPage);
        detailsPage.bindDataWithUrl(profileUrl);
    
    }*/
    
 /*   function toastAndPop(pagepop,msg){
        
        toastMsgPopLastPage.body = msg;
        toastMsgPopLastPage.pageToPop = pagepop
        toastMsgPopLastPage.show()
        
    }
    function toast(msg) {
        toastMsg.body = msg;
        toastMsg.show()
    }
    function checkOnline(){
        if(_controller.isOnline()){
            return true;
        }
        else{
            toast(qsTr("Please check your connection and try again!"))
            return false;
        }
    }
            
    function navToLIHome(){
        var homePage = updatesTab.content.at(0)
        updatesTab.content.navigateTo(homePage)
        activeTab = updatesTab

    }        
}
*/