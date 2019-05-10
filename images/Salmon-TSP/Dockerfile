# Get the base Ubuntu image from Docker Hub
FROM ubuntu:latest

#Create argument for container
#ENV NAME VAR
# Update apps on the base image
RUN apt-get -y update && apt-get install -y

# Get the GCC preinstalled image from Docker Hub
FROM gcc:4.9

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY SalmonTSP/temp /SalmonTSP

# Specify the working directory
WORKDIR /SalmonTSP/

# Use Clang to compile the Test.cpp source file
RUN g++ -o Salmon *.cpp *.h

WORKDIR /

