// Navigation pane project template
import bb.cascades 1.0
import "../controls" 1.0
import bbmoviez.app 1.0

Page {
    // page with a picture detail
    id: pgDetail
    property string movieName
    /*actions: [
        // create navigation panel actions here
        ActionItem {
            title: qsTr("Break")
            onTriggered: {
                imgView.imageSource = "asset:///images/picture1br.png"
            }
        }
    ]*/
    paneProperties: NavigationPaneProperties {
        backButton: ActionItem {
            onTriggered: {
                // define what happens when back button is pressed here
                // in this case is closed the detail page
                navigationPane.pop()
            }
        }
    }
    PageBkg {        
        /*Label {
            text: qsTr("Page 2")
            horizontalAlignment: HorizontalAlignment.Center
            textStyle {
                base: SystemDefaults.TextStyles.TitleText
                color: Color.Yellow
            }
        }
        ImageView {
            id: imgView
            imageSource: "asset:///images/picture1.png"
            horizontalAlignment: HorizontalAlignment.Center
        }
        Label {
            text: qsTr("Picture description")
            horizontalAlignment: HorizontalAlignment.Center
        }*/
        ListView {
            id: moviesListView
            objectName:"moviesList"
            dataModel: ListDataModel{}
            
            onTriggered: {
                var selectedItem = moviesListView.dataModel.data(indexPath);
                
                //if (selectedItem.type == "item"){                                    
		            var page = movieDetailsPage.createObject();
                    navigationPane.push(page);
                    _searchController.searchMovieDetails(selectedItem.firstName);
                    //movieItem.ListItem.view.getController().searchMovieDetails(name);
                    //page.bindData();
                    //_searchController.searchMovieDetails(selectedItem.movieId);             
                //}                
            }
            function getController() {
                return _searchController;
            } 
            function pushDetails() {
                var page = movieDetailsPage.createObject();
                navigationPane.push(page);    
            }                
            listItemComponents: [  
                ListItemComponent {
                    type: "header"
                    Container {
                        preferredWidth: 768
	                    Label {
	                        horizontalAlignment: HorizontalAlignment.Center
	                        text: "Movies"
	                        textStyle.color: Color.Red
	                        textStyle.fontWeight: FontWeight.Bold
            	            textStyle.fontSize: FontSize.XXLarge
	                    }
	                    Container {
                            horizontalAlignment: HorizontalAlignment.Fill
                            preferredHeight: 4
                            background: Color.create("#00A7DE")
                        } 
	                }
                },                                             
                ListItemComponent {
                    id:liMovies
                    type: "item" 
                    property string movieName: ListItemData.firstName                                                          
                    Movie {          
                        movieId: ListItemData.id
                        name: ListItemData.firstName
                        members: ListItemData.lastName
                        //pictureUrl: ListItemData.employeeNumber                                                         
                    }                               
                }
            ]                
        }
    }
    function bindData() {              
        _searchController.bindData("moviesList");      
    }
}
