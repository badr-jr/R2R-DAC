# R2R DAC AUDIO PLAYER (STM32 Microcontroller Based)
- Digital To Analog Converter That Is Used To Output Audio At Frequency Of 8KHZ On Basic Speaker (Based On STM32 Microcontroller).
- R2R Digital To Analog Converter Circuit Is Designed And Implemented.
# Table Of Contents
- [General Info](#general-info)
- [Technologies and Hardware](#Technologies-and-Hardware)
- [Configurations](#configurations)
# General Info
- This project implements DAC That Helps To Ouput Audio At 8 KHZ On Speaker, 8MKHZ Is Determined to Save Storage.
- Audio Shouldn't Exceed 5 Seconds As We Have Limited Storage (64KB).
- Audio Should Be At 8KHZ Frequence And Converted To hex file.
- DAC Resolution Of 8 Bits Is Used.
- DAC Circuit:


![DAC_Circuit](https://user-images.githubusercontent.com/74314248/173679858-2c3ad055-9f46-4bc4-907b-22b2c5460cf1.png)

# Technologies and Hardware
- C language.
- STM32 Microcontroller is used.
- Simple Speaker.
- 16 Resistors For 8 Bit DAC Circuit (8(R) and 8(2R)).
# Configurations
- 1 Tick Must Be Configured To Be Equal To 1 Microsecond.
- Const Keyword Is Used Before Array Of Samples In Audio hex File In Order To Store Array Of Samples In ROM (Flash).
