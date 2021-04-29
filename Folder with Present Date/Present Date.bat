@echo off
cls

if not exist "%cd%\%date%" (
	mkdir "%cd%\%date%"
)

