// Navigation pane project template
import bb.cascades 1.0
//import "../controls" 1.0

Page {
    // page with a picture detail
    id: pgDetail
    actions: [
        // create navigation panel actions here
        ActionItem {
            title: qsTr("Break")
            onTriggered: {
                imgView.imageSource = "asset:///images/picture1br.png"
            }
        }
    ]
    paneProperties: NavigationPaneProperties {
        backButton: ActionItem {
            onTriggered: {
                // define what happens when back button is pressed here
                // in this case is closed the detail page
                navigationPane.pop()
            }
        }
    }
    Container {
        background: Color.Black
        Label {
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
        }
        ListView {
            id: moviesListView
            objectName:"moviesList"
            
            onTriggered: {
                var selectedItem = dataModel.data(indexPath);
                
                /*if (selectedItem.type == "SuggestedIndustries" || 
                    selectedItem.type == "FollowingIndustries"){                
                    var activeTab = tabPane.activeTab;
		            var detailsPage = industryNewsPage.createObject();
		            activeTab.content.push(detailsPage);
		            _industriesController.fetchInustryArticles(selectedItem.industryId);
		            detailsPage.bindData(selectedItem.name,selectedItem.industryId,selectedItem.isFollowing);             
                }
                else if (selectedItem.type == "MoreSuggestions"){                
                    var activeTab = tabPane.activeTab;
		            var detailsPage = suggestedIndustriesPage.createObject();
		            activeTab.content.push(detailsPage);
		            detailsPage.bindData();                 
                }*/
            }
            function getController() {
                
            }                
            listItemComponents: [                                               
                ListItemComponent {
                    id:liMovies
                    type: "movies"                                 
                    /*Movie {                        
                        name: "name"//ListItemData.name
                        members: "details"//ListItemData.details
                        pictureUrl: "pictureUrl"//ListItemData.picUrl                                                         
                    } */
                    Container {
                        property string name
                        property string members
                        property string pictureUrl
                    
                        layout: DockLayout {
                        }
                        
                        Container{
                    
                            horizontalAlignment: HorizontalAlignment.Left
                            verticalAlignment: VerticalAlignment.Fill
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                        
                    	    ImageView {
                    	        preferredWidth: 81
                    	        minWidth: 81
                    	        preferredHeight: 81
                    	        imageSource: pictureUrl                    	        
                    	    }
                    	    
                    	    Container {
                    	        layout: StackLayout {
                    	        }
                    	        topPadding: 5
                    	        bottomPadding: 5
                    	        leftMargin: 20
                    	        
                    	        Container {
                    		        Label {
                    		            text: "name"//name
                    		            textStyle.fontWeight: FontWeight.W500
                    		            textStyle.fontSize: FontSize.Large
                    		            textStyle.color: Color.White
                    		        }	        
                    		    }
                    	        
                    	        Container {
                    		        Label {
                    		            text: "details"//members
                    		            textStyle.fontWeight: FontWeight.Normal
                    		            textStyle.fontSize: FontSize.Medium
                    		            textStyle.color: Color.White	            
                    		        }	        
                    		    }
                    	    }
                        }                        
                    }                       
                }
            ]                
        }
    }
    function bindData() {              
        _searchController.bindData("moviesList");      
    }
}
