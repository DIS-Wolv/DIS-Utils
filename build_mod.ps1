
$ModName = "@DIS-Utils"
$fileToAdd = @(
	"dis.jpg",
	"disMoto.jpg",
	"dis.paa",
	"mod.cpp"
)
$KeyFolder = "C:\Users\SteamCMD\Documents\Arma3Keys"
$AddonBuilderPath = "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\AddonBuilder\AddonBuilder.exe"

# check if the mod directory already exists
if (Test-Path -Path $ModName) {
	Write-Output "Removing existing mod directory: $ModName"
	Remove-Item -Path $ModName -Force -Recurse
}

# create the mod directory structure
New-Item -Path $ModName -ItemType Directory
New-Item -Path "$ModName\addons" -ItemType Directory
New-Item -Path "$ModName\keys" -ItemType Directory

# Copy files to the mod directory
ForEach ($file in $fileToAdd) {
	$sourcePath = ".\$file"
	$destinationPath = "$ModName\$file"
	
	Copy-Item -Path $sourcePath -Destination $destinationPath -Force
	Write-Output "Adding $file to $ModName"
}

# Define paths for the tools used in the build process
$BinarizePath = "-binarize='C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\Binarize\binarize.exe'"
$FilebankPath = "-filebank='C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\FileBank\FileBank.exe'"
$CfgConvertPath = "-cfgconvert='C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\CfgConvert\CfgConvert.exe'"
$DsSignFile = "dssignfile='C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\DSSignFile\DSSignFile.exe'"

# Process each directory in the addons folder
$destinationDir = "$(Get-Location)\$ModName\addons\"
ForEach ($dir in (Get-ChildItem -Path ".\addons" -Directory)) {
	write-Output "Processing directory: $($dir.name)"
	$sourcePath = "$(Get-Location)\addons\$($dir.name)"
	& $AddonBuilderPath $sourcePath $destinationDir -packonly -sign="$KeyFolder\dis.biprivatekey" $BinarizePath $FilebankPath $CfgConvertPath $DsSignFile
}

# create the key file
$pubKeyFilePath = "$KeyFolder\dis.bikey"
Copy-Item -Path $pubKeyFilePath -Destination "$ModName\keys\dis.bikey" -Force
