import bb.cascades 1.0

Container {
    id: movieItem
    
    property string name
    property string members
    //property string pictureUrl  
    property string movieId  

    preferredWidth: 768
    layout: StackLayout {        
    }
    
    Container{
        
        horizontalAlignment: HorizontalAlignment.Left
        verticalAlignment: VerticalAlignment.Fill
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }
    
	    /*ImageView {
	        preferredWidth: 81
	        minWidth: 81
	        preferredHeight: 81
	        imageSource: ""//pictureUrl	        
	    }*/
	    
	    Container {
	        layout: StackLayout {
	        }
	        topPadding: 5
	        bottomPadding: 5
	        leftMargin: 20
	        
	        Container {
		        Label {
		            text: name
		            textStyle.fontWeight: FontWeight.W500
		            textStyle.fontSize: FontSize.Large
		            textStyle.color: Color.White
		        }	        
		    }
	        
	        Container {
		        Label {
		            text: members
		            textStyle.fontWeight: FontWeight.Normal
		            textStyle.fontSize: FontSize.Medium
		            textStyle.color: Color.White	            
		        }	        
		    }		    
	    }	        
    }    
    Container {
        horizontalAlignment: HorizontalAlignment.Fill
        preferredHeight: 4
        background: Color.create("#00A7DE")
    }
    /*onTouch: {
        if(event.isDown()) {                             
            movieItem.ListItem.view.pushDetails();
            movieItem.ListItem.view.getController().searchMovieDetails(name);                      
        }
    } */  	    
}