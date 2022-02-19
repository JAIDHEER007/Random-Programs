from http.server import BaseHTTPRequestHandler, HTTPServer
import socket
import time

# Change these
# hostName = socket.gethostbyname(socket.gethostname())
# hostName = ""  # Private IP Address
serverPort = 8080

class MyServer(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        self.wfile.write(bytes("""
        <html>
            <head>
                <title>Hello</title>
            </head>
            <body>
                <h1>Hello World!</h1>
                <div>
                    <img src="https://c.tenor.com/mGgWY8RkgYMAAAAC/hello-world.gif" alt = "Hello World Gif">
                </div>
                <br>
                <div>
                    <img src = "https://upload.wikimedia.org/wikipedia/commons/c/cc/Digital_rain_animation_medium_letters_shine.gif" alt = "MRain Gif">
                </div>
            </body>
        </html>""", "utf-8"))
        # self.wfile.write(bytes("<p>Request: %s</p>" % self.path, "utf-8"))

if __name__ == "__main__":        
    webServer = HTTPServer((hostName, serverPort), MyServer)
    print("Server started http://%s:%s" % (hostName, serverPort))

    try:
        webServer.serve_forever()
    except KeyboardInterrupt:
        pass

    webServer.server_close()
    print("Server stopped.")
