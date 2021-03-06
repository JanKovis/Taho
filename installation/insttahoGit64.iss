; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Taho"
#define MyAppVersion "4.08"
#define MyAppPublisher "Dimitri Junker"
#define MyAppURL "www.dimitri-junker.de/html/openstreetmap.html"
#define MyAppExeName "Taho.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{F44AC5AC-771A-44E8-8186-C4B0FF0FA0E2}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
#define AppVersion4FN            Copy(MyAppVersion, 1, Pos(".", MyAppVersion) - 1) + "_" + Copy(MyAppVersion, Pos(".", MyAppVersion) + 1)
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
OutputDir=G:\upload\EIGENES\OSM\Taho\Inno
OutputBaseFilename=taho64_setup_{#AppVersion4FN}
LicenseFile=Docu\Lizenz_en.txt
Compression=lzma
SolidCompression=yes
; "ArchitecturesAllowed=x64" specifies that Setup cannot run on
; anything but x64.
ArchitecturesAllowed=x64
; "ArchitecturesInstallIn64BitMode=x64" requests that the install be
; done in "64-bit mode" on x64, meaning it should use the native
; 64-bit Program Files directory and the 64-bit view of the registry.
ArchitecturesInstallIn64BitMode=x64

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"; LicenseFile: "Docu\Lizenz_en.txt"
Name: "french"; MessagesFile: "compiler:Languages\French.isl"; LicenseFile: Docu\Lizenz_fr.txt
Name: "german"; MessagesFile: "compiler:Languages\German.isl"; LicenseFile: Docu\Lizenz_de.txt

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked


[Files]
Source: "build-Taho-Desktop_Qt_5_12_0_MinGW_64_bit-Release\release\Taho.exe"; DestDir: "{app}"; Flags: ignoreversion 
Source: "Docu\GNU LGPL v2.1_DE.html"; DestDir: "{app}\Docu"; Flags: ignoreversion
Source: "Docu\GNU LGPL v2.1_EN.html"; DestDir: "{app}\Docu"; Flags: ignoreversion
Source: "Docu\GNU LGPL v2.1_FR.html"; DestDir: "{app}\Docu"; Flags: ignoreversion
Source: "Docu\gpl-3.0_de.htm"; DestDir: "{app}\Docu"; Flags: ignoreversion
Source: "Docu\gpl-3.0_en.htm"; DestDir: "{app}\Docu"; Flags: ignoreversion
Source: "Docu\gpl-3.0_fr.htm"; DestDir: "{app}\Docu"; Flags: ignoreversion
Source: "Docu\liesmich.pdf"; DestDir: "{app}\Docu"; Flags: ignoreversion
Source: "Docu\lisezmoi.pdf"; DestDir: "{app}\Docu"; Flags: ignoreversion
Source: "Docu\readme.pdf"; DestDir: "{app}\Docu"; Flags: ignoreversion
Source: "Taho\taho_en.qm"; DestDir: "{app}"; Flags: ignoreversion
Source: "Taho\taho_fr.qm"; DestDir: "{app}"; Flags: ignoreversion
Source: "build-Taho-Desktop_Qt_5_12_0_MinGW_64_bit-Release\release\?*.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "build-Taho-Desktop_Qt_5_12_0_MinGW_64_bit-Release\release\platforms\?*"; DestDir: "{app}\platforms"; Flags: ignoreversion  
Source: "build-Taho-Desktop_Qt_5_12_0_MinGW_64_bit-Release\release\bearer\?*"; DestDir: "{app}\bearer"; Flags: ignoreversion
Source: "build-Taho-Desktop_Qt_5_12_0_MinGW_64_bit-Release\release\iconengines\?*"; DestDir: "{app}\iconengines"; Flags: ignoreversion
Source: "build-Taho-Desktop_Qt_5_12_0_MinGW_64_bit-Release\release\imageformats\?*"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "build-Taho-Desktop_Qt_5_12_0_MinGW_64_bit-Release\release\styles\?*"; DestDir: "{app}\styles"; Flags: ignoreversion
Source: "build-Taho-Desktop_Qt_5_12_0_MinGW_64_bit-Release\release\translations\?*"; DestDir: "{app}\translations"; Flags: ignoreversion

; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

