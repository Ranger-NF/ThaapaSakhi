import WebSocket from "ws";

const ws = new WebSocket("wss://ntfy.sh/thaapasakhi-server/ws");

ws.addEventListener("message", function (event) {
  const data = JSON.parse(event.data);
  console.log(data);
});
