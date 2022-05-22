module com.example.audioheaven {
    requires javafx.controls;
    requires javafx.fxml;
    requires org.jetbrains.annotations;
    requires jaco.mp3.player;
    requires java.desktop;
    requires java.logging;


    opens com.example.audioheaven to javafx.fxml;
    exports com.example.audioheaven;
}