import WebSocket from "ws";

const musicList = {
  24: "Himamazha",
  26: "Aha",
};

const ws = new WebSocket("wss://ntfy.sh/thaapasakhi-server/ws");

ws.addEventListener("message", function (event) {
  const data = JSON.parse(event.data);
  console.log(data);

  analyzeTemperature(parseInt(data.message));
});

function analyzeTemperature(tempInCelcius) {
  const musicName = musicList[tempInCelcius];
  console.log(musicName);
  if (!musicName) {
    console.log("No music for this temperature");
  } else {
    console.log(musicName);
  }
}
