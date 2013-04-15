import bb.cascades 1.0
import bbmoviez.app 1.0
import "../"
import "../controls" 1.0
Page {
	PageBkg{
	    preferredWidth: 768
	    preferredHeight: 1280
	    topPadding: 260
	    layout: StackLayout {}	    
	    
		    WebImageView {
		        horizontalAlignment: HorizontalAlignment.Center
		        verticalAlignment: HorizontalAlignment.Center		        
	            id: fullScreen
	            minWidth: 660
	            maxWidth: 660
	            minHeight: 660
	            maxHeight: 660	                   
	        }
	   
	}
	function populateUI(imageUrl) {
	    fullScreen.url = imageUrl;
	}
	
	onCreationCompleted: {
	    _searchController.movieDetailsReady.connect(populateUI);
	}
}