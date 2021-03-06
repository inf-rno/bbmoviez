import bb.cascades 1.0
import "../controls" 1.0

Page {
    property int screenWidth: 768
    property int screenHeight: 1280;
    // page with a picture thumbnail
    PageBkg {
        preferredWidth: screenWidth
        preferredHeight: screenHeight
        layout: StackLayout {
            orientation: LayoutOrientation.TopToBottom
        }
        Container {
            leftPadding: 25
            rightPadding: 25
            //background: Color.Red
            preferredHeight: screenHeight
            preferredWidth: screenWidth
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: HorizontalAlignment.Center
            layout: StackLayout {
                orientation: LayoutOrientation.TopToBottom
            }
            TextField {
                id: searchField
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: HorizontalAlignment.Center
                inputMode: TextFieldInputMode.Text
                input {
                    onSubmitted: {
                        _searchController.search(searchField.text);
                    }
                }
            }
            Button {
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: qsTr("Show detail")
                imageSource: "asset:///images/picture1thumb.png"
                onClicked: {
                    _searchController.searchResolved.connect(navDetails);
                    _searchController.search(searchField.text);
                }
            }
            Button {
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Bottom
                text: qsTr("Show Nodes")
                onClicked: {
                    _searchController.handleMoviePicked();
                }
            }
        }
    }
    function navDetails() {
        //_searchController.bindData();
        var page = movieListPage.createObject();
        navigationPane.push(page);
        page.bindData();
    }
}
