import bb.cascades 1.0


Container {
    preferredWidth: 768
    preferredHeight: 1280
    background: back.imagePaint
    attachedObjects: [
        ImagePaintDefinition {
            id: back
            repeatPattern: RepeatPattern.XY
            imageSource: "asset:///images/bkg.png"
        }
    ]
}