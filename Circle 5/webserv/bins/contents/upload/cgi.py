#!/usr/bin/env python

# print("Status: 200 OK")
# print("Content-Type: text/html\r\n\r\n")
# response_body = """<!DOCTYPE html><html><head><title>Hello World CGI</title></head><body><h1>Hello, World!</h1></body></html>\0\r\n\r\n"""
# print(response_body)

str = "Status: 200 OK\r\n" + "Content-Type: text/html\r\n\r\n" + \
    "<!DOCTYPE html><html><head><title>Hello World CGI</title></head><body>" + \
    "<h1>Hello, World!</h1></body></html>\0\r\n\r\n"
print(str)