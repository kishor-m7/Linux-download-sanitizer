chrome.downloads.onCreated.addListener((downloadItem) => {

    console.log("Download detected:", downloadItem.filename);

    fetch("http://localhost:5000/scan", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify({
            file_path: downloadItem.filename,
            ip: "192.168.1.10"
        })
    })
    .then(res => res.json())
    .then(data => {
        if (data.status === "malicious") {
            chrome.notifications.create({
                type: "basic",
                iconUrl: "icon.png",
                title: " Threat Detected",
                message: "Malicious file blocked!"
            });
        }
    });
});