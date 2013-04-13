import bb.cascades 1.0

Page {
    // page with a picture thumbnail
    Container {
        background: Color.Black
        layout: DockLayout {
        }
        Button {
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            text: qsTr("Show detail")
            imageSource: "asset:///images/picture1thumb.png"
            onClicked: {
                // show detail page when the button is clicked                         
                var page = detailsPage.createObject();
                navigationPane.push(page);
            }           
        }
    }
}