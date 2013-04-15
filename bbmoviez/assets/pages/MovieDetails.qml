import bb.cascades 1.0
import bbmoviez.app 1.0
import "../"
import "../controls" 1.0

Page{
    property string fullImageUrl
	PageBkg{
	ScrollView {
	    Container {
	        layout: StackLayout {}
			Container {	    	    
			    layout: StackLayout {
			        orientation: LayoutOrientation.LeftToRight
			    }
			    Container {
			        topPadding: 10
			        leftPadding: 10
			        rightPadding: 10
			        bottomPadding: 10
			        background: Color.White
			        WebImageView {
			            id: thumbnail
			            minWidth: 320
			            maxWidth: 320
			            minHeight: 320
			            maxHeight: 320			                   
			        }
			        
			        onTouch: {
		                if(event.isDown()) {
		                    var page = fullImagePage.createObject();
                            navigationPane.push(page);     
                            page.populateUI(fullImageUrl);                            		                                      
		                }
		            } 
			    }
			    Container {
			        preferredWidth: 768			        
			        layout: StackLayout {
			        }
			        bottomPadding: 10
			        leftMargin: 20
			        Container {
			
			            layout: DockLayout {}		            
			            preferredWidth: 768 
			            Container {
			                id: containerId
			                function getContainerWidth() {
			
			                    var width = 768;                    
			
			                    return width;
			
			                }
			                maxWidth: getContainerWidth()
			                horizontalAlignment: HorizontalAlignment.Left
			                verticalAlignment: VerticalAlignment.Center
			                layout: StackLayout {
			                    //orientation: LayoutOrientation.LeftToRight
			                }
			                Label {
			                    id: movieTitle		                    
			                    maxWidth: containerId.getContainerWidth()
			                    textStyle.color: Color.Red
			                    textStyle.fontWeight: FontWeight.Bold
	            	            textStyle.fontSize: FontSize.XLarge
	            	            multiline: true
			                }
			                Label {    
			                    id: mvYear                		                    		                    
			                    textStyle.color: Color.White
			                    textStyle.fontWeight: FontWeight.Normal
	            	            textStyle.fontSize: FontSize.Medium
			                }
			                Label { 
			                    id: mvRating                   		                    		                    
			                    textStyle.color: Color.White
			                    textStyle.fontWeight: FontWeight.Normal
	            	            textStyle.fontSize: FontSize.Medium
			                }			                
			                Label {
			                    id: mvRT                    		                    		                    
			                    textStyle.color: Color.White
			                    textStyle.fontWeight: FontWeight.Normal
	            	            textStyle.fontSize: FontSize.Medium
			                }
			            }            
			        }			        			    
			    }
			}//
			Container {
			    topPadding: 40
			    leftPadding: 20
			    rightPadding: 20
			    Label {
                    id: mvCC                    		                    		                    
                    textStyle.color: Color.White
                    textStyle.fontWeight: FontWeight.Normal
    	            textStyle.fontSize: FontSize.Medium
    	            multiline: true
                }
			}
			Container {
			    topPadding: 40
			    leftPadding: 20
			    rightPadding: 20
				Label {    
                    id: mvCR                		                    		                    
                    textStyle.color: Color.White
                    textStyle.fontWeight: FontWeight.Normal
    	            textStyle.fontSize: FontSize.Medium
                }
                Label { 
                    id: mvCS                   		                    		                    
                    textStyle.color: Color.White
                    textStyle.fontWeight: FontWeight.Normal
    	            textStyle.fontSize: FontSize.Medium
                }
                Label {
                    id: mvAR                    		                    		                    
                    textStyle.color: Color.White
                    textStyle.fontWeight: FontWeight.Normal
    	            textStyle.fontSize: FontSize.Medium
    	            multiline: true
                }
                Label {
                    id: mvAS                    		                    		                    
                    textStyle.color: Color.White
                    textStyle.fontWeight: FontWeight.Normal
    	            textStyle.fontSize: FontSize.Medium
                }
		    }
		    Container {
			    leftPadding: 20
			    rightPadding: 20
			    topPadding: 10
				Label {    
                    id: synopsis                		                    		                    
                    textStyle.color: Color.White
                    textStyle.fontWeight: FontWeight.Normal
    	            textStyle.fontSize: FontSize.Medium
                }                
		    }
		    Container {
			    leftPadding: 20
			    rightPadding: 20
			    topPadding: 10
				Label {    
                    id: cast                		                    		                    
                    textStyle.color: Color.White
                    textStyle.fontWeight: FontWeight.Normal
    	            textStyle.fontSize: FontSize.Medium
    	            multiline: true
                }                
		    }
		}
	}
}
	function populateUI() {
	    movieTitle.text = _searchController.movieTitle;
	    mvYear.text = "Year: " +  _searchController.movieYear;
	    mvRating.text = "Rating: " + _searchController.movieRating;
	    mvCC.text =  "Critics Consensus: " + _searchController.movieCritics;
	    mvRT.text = "Runtime: " + _searchController.movieRuntime;
	    
	    mvCR.text = "Critics Rating: " +  _searchController.movieCR;
	    mvCS.text = "Critics Score: " +  _searchController.movieCS;
	    mvAR.text = "Audience Rating: " + _searchController.movieAR;
	    mvAS.text = "Audience Score: " + _searchController.movieAS;
	    
	    synopsis.text = "Synopsis: " + _searchController.movieS;
	    
	    cast.text = "Cast: " + _searchController.movieCast;
	    
	    thumbnail.url = _searchController.movieThumbnail;
	    fullImageUrl = _searchController.movieFullScreen;
	}
	onCreationCompleted: {
	    _searchController.movieDetailsReady.connect(populateUI);	    
	}
	function bindData() {              
        //_searchController.getMovieDetails();      
    }
}