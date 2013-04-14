import bb.cascades 1.0
import custom.controls 1.0

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
    
    NetImageView {
        preferredWidth: 81
        minWidth: 81
        preferredHeight: 81
        imageUrl: pictureUrl
        defaultImage: "asset:///images/controls/default_group.png"
    }
    
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
	            textStyle.color: itemTextColor
	        }	        
	    }
        
        Container {
	        Label {
	            text: members
	            textStyle.fontWeight: FontWeight.Normal
	            textStyle.fontSize: FontSize.Medium
	            textStyle.color: itemTextColor	            
	        }	        
	    }
    }
    }
    Container {
        layout: DockLayout {
        }
        minWidth: sizeStyle.profChevSize
        maxWidth: sizeStyle.profChevSize
        horizontalAlignment: HorizontalAlignment.Right
        verticalAlignment: VerticalAlignment.Fill
        ImageView {
            preferredWidth: 21
            preferredHeight: 31
            imageSource: chevronSrc
            horizontalAlignment: HorizontalAlignment.Right
            verticalAlignment: VerticalAlignment.Center
        }
    }
}