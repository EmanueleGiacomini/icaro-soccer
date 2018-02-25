<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="8.6.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="14" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Teensy_3_and_LC_Series_Boards_v1.4">
<packages>
<package name="TEENSY_3.0-3.2_ALL_PINS_&amp;_PADS">
<pad name="GND" x="-7.62" y="16.51" drill="0.9652"/>
<pad name="0" x="-7.62" y="13.97" drill="0.9652"/>
<pad name="1" x="-7.62" y="11.43" drill="0.9652"/>
<pad name="2" x="-7.62" y="8.89" drill="0.9652"/>
<pad name="3" x="-7.62" y="6.35" drill="0.9652"/>
<pad name="4" x="-7.62" y="3.81" drill="0.9652"/>
<pad name="5" x="-7.62" y="1.27" drill="0.9652"/>
<pad name="6" x="-7.62" y="-1.27" drill="0.9652"/>
<pad name="7" x="-7.62" y="-3.81" drill="0.9652"/>
<pad name="8" x="-7.62" y="-6.35" drill="0.9652"/>
<pad name="9" x="-7.62" y="-8.89" drill="0.9652"/>
<pad name="10" x="-7.62" y="-11.43" drill="0.9652"/>
<pad name="11" x="-7.62" y="-13.97" drill="0.9652"/>
<pad name="12" x="-7.62" y="-16.51" drill="0.9652"/>
<pad name="VBAT" x="-5.08" y="-16.51" drill="0.9652"/>
<pad name="3.3V1" x="-2.54" y="-16.51" drill="0.9652"/>
<pad name="GND1" x="0" y="-16.51" drill="0.9652"/>
<pad name="PGM" x="2.54" y="-16.51" drill="0.9652"/>
<pad name="RESET/DAC" x="5.08" y="-16.51" drill="0.9652"/>
<pad name="13" x="7.62" y="-16.51" drill="0.9652"/>
<pad name="14/A0" x="7.62" y="-13.97" drill="0.9652"/>
<pad name="15/A1" x="7.62" y="-11.43" drill="0.9652"/>
<pad name="16/A2" x="7.62" y="-8.89" drill="0.9652"/>
<pad name="17/A3" x="7.62" y="-6.35" drill="0.9652"/>
<pad name="18/A4" x="7.62" y="-3.81" drill="0.9652"/>
<pad name="19/A5" x="7.62" y="-1.27" drill="0.9652"/>
<pad name="20/A6" x="7.62" y="1.27" drill="0.9652"/>
<pad name="21/A7" x="7.62" y="3.81" drill="0.9652"/>
<pad name="22/A8" x="7.62" y="6.35" drill="0.9652"/>
<pad name="23/A9" x="7.62" y="8.89" drill="0.9652"/>
<pad name="3.3V" x="7.62" y="11.43" drill="0.9652"/>
<pad name="AGND" x="7.62" y="13.97" drill="0.9652"/>
<pad name="VIN" x="7.62" y="16.51" drill="0.9652"/>
<wire x1="-8.89" y1="17.78" x2="8.89" y2="17.78" width="0.127" layer="51"/>
<wire x1="8.89" y1="17.78" x2="8.89" y2="-17.78" width="0.127" layer="51"/>
<wire x1="8.89" y1="-17.78" x2="-8.89" y2="-17.78" width="0.127" layer="51"/>
<wire x1="-8.89" y1="-17.78" x2="-8.89" y2="17.78" width="0.127" layer="51"/>
<wire x1="-1.27" y1="16.51" x2="1.27" y2="16.51" width="0.2032" layer="21"/>
<wire x1="1.27" y1="16.51" x2="1.27" y2="17.78" width="0.2032" layer="21"/>
<wire x1="1.27" y1="17.78" x2="8.89" y2="17.78" width="0.2032" layer="21"/>
<wire x1="8.89" y1="17.78" x2="8.89" y2="-17.78" width="0.2032" layer="21"/>
<wire x1="8.89" y1="-17.78" x2="-8.89" y2="-17.78" width="0.2032" layer="21"/>
<wire x1="-8.89" y1="-17.78" x2="-8.89" y2="17.78" width="0.2032" layer="21"/>
<wire x1="-8.89" y1="17.78" x2="-1.27" y2="17.78" width="0.2032" layer="21"/>
<wire x1="-1.27" y1="17.78" x2="-1.27" y2="16.51" width="0.2032" layer="21"/>
<text x="-3.81" y="13.97" size="1.27" layer="25" font="vector">&gt;NAME</text>
<text x="-3.81" y="5.08" size="1.27" layer="27" font="vector">&gt;VALUE</text>
<pad name="VUSB" x="5.08" y="13.97" drill="0.9652"/>
<pad name="AREF" x="5.08" y="8.89" drill="0.9652"/>
<pad name="A10" x="5.08" y="6.35" drill="0.9652"/>
<pad name="A11" x="5.08" y="3.81" drill="0.9652"/>
<pad name="28" x="0" y="-13.97" drill="0.9652"/>
<pad name="29" x="2.54" y="-13.97" drill="0.9652"/>
<pad name="27" x="0" y="-11.43" drill="0.9652"/>
<pad name="26" x="0" y="-8.89" drill="0.9652"/>
<pad name="25" x="0" y="-6.35" drill="0.9652"/>
<pad name="24" x="0" y="-3.81" drill="0.9652"/>
<pad name="30" x="2.54" y="-11.43" drill="0.9652"/>
<pad name="31" x="2.54" y="-8.89" drill="0.9652"/>
<pad name="32" x="2.54" y="-6.35" drill="0.9652"/>
<pad name="33" x="2.54" y="-3.81" drill="0.9652"/>
<pad name="3.3V2" x="2.54" y="-1.27" drill="0.9652"/>
<pad name="A13" x="2.54" y="1.27" drill="0.9652"/>
<pad name="GND2" x="0" y="-1.27" drill="0.9652"/>
<pad name="A12" x="0" y="1.27" drill="0.9652"/>
</package>
</packages>
<symbols>
<symbol name="TEENSY_3.1-3.2_ALL_PINS_AND_PADS">
<wire x1="-17.78" y1="-35.56" x2="17.78" y2="-35.56" width="0.254" layer="94"/>
<wire x1="17.78" y1="-35.56" x2="17.78" y2="33.02" width="0.254" layer="94"/>
<wire x1="17.78" y1="33.02" x2="-17.78" y2="33.02" width="0.254" layer="94"/>
<wire x1="-17.78" y1="33.02" x2="-17.78" y2="-35.56" width="0.254" layer="94"/>
<pin name="12/MISO" x="-22.86" y="-2.54" visible="pin" length="middle"/>
<pin name="11/MOSI" x="-22.86" y="0" visible="pin" length="middle"/>
<pin name="10/TX2/PWM" x="-22.86" y="2.54" visible="pin" length="middle"/>
<pin name="9/RX2/PWM" x="-22.86" y="5.08" visible="pin" length="middle"/>
<pin name="8/TX3" x="-22.86" y="7.62" visible="pin" length="middle"/>
<pin name="7/RX3" x="-22.86" y="10.16" visible="pin" length="middle"/>
<pin name="6/PWM" x="-22.86" y="12.7" visible="pin" length="middle"/>
<pin name="5/PWM" x="-22.86" y="15.24" visible="pin" length="middle"/>
<pin name="4/CAN-RX/PWM" x="-22.86" y="17.78" visible="pin" length="middle"/>
<pin name="3/CAN-TX/PWM" x="-22.86" y="20.32" visible="pin" length="middle"/>
<pin name="2" x="-22.86" y="22.86" visible="pin" length="middle"/>
<pin name="1/TX1/T" x="-22.86" y="25.4" visible="pin" length="middle"/>
<pin name="0/RX1/T" x="-22.86" y="27.94" visible="pin" length="middle"/>
<pin name="GND" x="22.86" y="20.32" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="VIN" x="22.86" y="27.94" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="AGND" x="22.86" y="7.62" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="3.3V" x="22.86" y="25.4" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="23/A9/T/PWM" x="-22.86" y="-30.48" visible="pin" length="middle"/>
<pin name="22/A8/T/PWM" x="-22.86" y="-27.94" visible="pin" length="middle"/>
<pin name="21/A7/PWM" x="-22.86" y="-25.4" visible="pin" length="middle"/>
<pin name="20/A6/PWM" x="-22.86" y="-22.86" visible="pin" length="middle"/>
<pin name="19/A5/T/SCL0" x="-22.86" y="-20.32" visible="pin" length="middle"/>
<pin name="18/A4/T/SDA0" x="-22.86" y="-17.78" visible="pin" length="middle"/>
<pin name="17/A3/T" x="-22.86" y="-15.24" visible="pin" length="middle"/>
<pin name="16/A2/T" x="-22.86" y="-12.7" visible="pin" length="middle"/>
<pin name="15/A1/T" x="-22.86" y="-10.16" visible="pin" length="middle"/>
<pin name="14/A0" x="-22.86" y="-7.62" visible="pin" length="middle"/>
<pin name="13/SCK/LED" x="-22.86" y="-5.08" visible="pin" length="middle"/>
<pin name="PGM" x="22.86" y="15.24" visible="pin" length="middle" rot="R180"/>
<pin name="VBAT" x="22.86" y="22.86" visible="pin" length="middle" direction="pwr" rot="R180"/>
<text x="-5.588" y="34.29" size="1.27" layer="95" font="vector" ratio="15">&gt;NAME</text>
<text x="-2.794" y="-38.1" size="1.27" layer="96" font="vector" ratio="15">&gt;VALUE</text>
<pin name="A10" x="22.86" y="-7.62" visible="pin" length="middle" rot="R180"/>
<pin name="A11" x="22.86" y="-5.08" visible="pin" length="middle" rot="R180"/>
<pin name="AREF" x="22.86" y="10.16" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="VUSB" x="22.86" y="30.48" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="24" x="-22.86" y="-33.02" visible="pin" length="middle"/>
<pin name="25/T/PWM" x="22.86" y="-33.02" visible="pin" length="middle" rot="R180"/>
<pin name="26/A15" x="22.86" y="-30.48" visible="pin" length="middle" rot="R180"/>
<pin name="27/A16" x="22.86" y="-27.94" visible="pin" length="middle" rot="R180"/>
<pin name="28/A17" x="22.86" y="-25.4" visible="pin" length="middle" rot="R180"/>
<pin name="29/A18/SCL1" x="22.86" y="-22.86" visible="pin" length="middle" rot="R180"/>
<pin name="30/A19/SDA1" x="22.86" y="-20.32" visible="pin" length="middle" rot="R180"/>
<pin name="31/A20" x="22.86" y="-17.78" visible="pin" length="middle" rot="R180"/>
<pin name="32/T/PWM" x="22.86" y="-15.24" visible="pin" length="middle" rot="R180"/>
<pin name="33/T" x="22.86" y="-12.7" visible="pin" length="middle" rot="R180"/>
<pin name="A12" x="22.86" y="-2.54" visible="pin" length="middle" rot="R180"/>
<pin name="A13" x="22.86" y="0" visible="pin" length="middle" rot="R180"/>
<pin name="A14/DAC" x="22.86" y="2.54" visible="pin" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="TEENSY_3.1-3.2_ALL_PINS&amp;PADS">
<description>Footprint for Teensy 3.1 or 3.2 board using all pads and all through-holes. Pads need a 2x7 0.1" SMD header.</description>
<gates>
<gate name="G$1" symbol="TEENSY_3.1-3.2_ALL_PINS_AND_PADS" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TEENSY_3.0-3.2_ALL_PINS_&amp;_PADS">
<connects>
<connect gate="G$1" pin="0/RX1/T" pad="0"/>
<connect gate="G$1" pin="1/TX1/T" pad="1"/>
<connect gate="G$1" pin="10/TX2/PWM" pad="10"/>
<connect gate="G$1" pin="11/MOSI" pad="11"/>
<connect gate="G$1" pin="12/MISO" pad="12"/>
<connect gate="G$1" pin="13/SCK/LED" pad="13"/>
<connect gate="G$1" pin="14/A0" pad="14/A0"/>
<connect gate="G$1" pin="15/A1/T" pad="15/A1"/>
<connect gate="G$1" pin="16/A2/T" pad="16/A2"/>
<connect gate="G$1" pin="17/A3/T" pad="17/A3"/>
<connect gate="G$1" pin="18/A4/T/SDA0" pad="18/A4"/>
<connect gate="G$1" pin="19/A5/T/SCL0" pad="19/A5"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="20/A6/PWM" pad="20/A6"/>
<connect gate="G$1" pin="21/A7/PWM" pad="21/A7"/>
<connect gate="G$1" pin="22/A8/T/PWM" pad="22/A8"/>
<connect gate="G$1" pin="23/A9/T/PWM" pad="23/A9"/>
<connect gate="G$1" pin="24" pad="24"/>
<connect gate="G$1" pin="25/T/PWM" pad="25"/>
<connect gate="G$1" pin="26/A15" pad="26"/>
<connect gate="G$1" pin="27/A16" pad="27"/>
<connect gate="G$1" pin="28/A17" pad="28"/>
<connect gate="G$1" pin="29/A18/SCL1" pad="29"/>
<connect gate="G$1" pin="3.3V" pad="3.3V 3.3V1 3.3V2"/>
<connect gate="G$1" pin="3/CAN-TX/PWM" pad="3"/>
<connect gate="G$1" pin="30/A19/SDA1" pad="30"/>
<connect gate="G$1" pin="31/A20" pad="31"/>
<connect gate="G$1" pin="32/T/PWM" pad="32"/>
<connect gate="G$1" pin="33/T" pad="33"/>
<connect gate="G$1" pin="4/CAN-RX/PWM" pad="4"/>
<connect gate="G$1" pin="5/PWM" pad="5"/>
<connect gate="G$1" pin="6/PWM" pad="6"/>
<connect gate="G$1" pin="7/RX3" pad="7"/>
<connect gate="G$1" pin="8/TX3" pad="8"/>
<connect gate="G$1" pin="9/RX2/PWM" pad="9"/>
<connect gate="G$1" pin="A10" pad="A10"/>
<connect gate="G$1" pin="A11" pad="A11"/>
<connect gate="G$1" pin="A12" pad="A12"/>
<connect gate="G$1" pin="A13" pad="A13"/>
<connect gate="G$1" pin="A14/DAC" pad="RESET/DAC"/>
<connect gate="G$1" pin="AGND" pad="AGND"/>
<connect gate="G$1" pin="AREF" pad="AREF"/>
<connect gate="G$1" pin="GND" pad="GND GND1 GND2"/>
<connect gate="G$1" pin="PGM" pad="PGM"/>
<connect gate="G$1" pin="VBAT" pad="VBAT"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
<connect gate="G$1" pin="VUSB" pad="VUSB"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="VHN5019">
<packages>
<package name="MOTOR-SHIELD">
<description>Motorshield Hbridge</description>
<wire x1="-7.62" y1="12.7" x2="-7.62" y2="-15.24" width="0.127" layer="21"/>
<wire x1="-7.62" y1="-15.24" x2="30.48" y2="-15.24" width="0.127" layer="21"/>
<wire x1="30.48" y1="-15.24" x2="30.48" y2="12.7" width="0.127" layer="21"/>
<wire x1="30.48" y1="12.7" x2="-7.62" y2="12.7" width="0.127" layer="21"/>
<pad name="GND" x="29.21" y="10.16" drill="0.8" shape="square"/>
<pad name="VOUT" x="29.21" y="7.62" drill="0.8" shape="octagon"/>
<pad name="GND2" x="29.21" y="5.08" drill="0.8" shape="octagon"/>
<pad name="VDD" x="29.21" y="2.54" drill="0.8" shape="octagon"/>
<pad name="INB" x="29.21" y="0" drill="0.8" shape="octagon"/>
<pad name="ENB/DIAGB" x="29.21" y="-2.54" drill="0.8" shape="octagon"/>
<pad name="CS" x="29.21" y="-5.08" drill="0.8" shape="octagon"/>
<pad name="PWM" x="29.21" y="-7.62" drill="0.8" shape="octagon"/>
<pad name="ENA/DIAGA" x="29.21" y="-10.16" drill="0.8" shape="octagon"/>
<pad name="INA" x="29.21" y="-12.7" drill="0.8" shape="octagon"/>
<pad name="GNDMOT-1" x="-5.08" y="-1.27" drill="2.2" shape="square"/>
<pad name="VMOT-1" x="-5.08" y="3.81" drill="2.2" shape="octagon"/>
<text x="-5.08" y="15.24" size="1.27" layer="25">&gt;NAME</text>
<pad name="VMOT-2" x="-6.35" y="5.08" drill="0.8" shape="octagon"/>
<pad name="VMOT-3" x="-6.35" y="2.54" drill="0.8" shape="octagon"/>
<pad name="GNDMOT-2" x="-6.35" y="0" drill="0.8" shape="octagon"/>
<pad name="GNDMOT-3" x="-6.35" y="-2.54" drill="0.8" shape="octagon"/>
<pad name="INMOT1" x="-5.08" y="-6.35" drill="2.2" shape="octagon"/>
<pad name="INMOT2" x="-5.08" y="-11.43" drill="2.2" shape="octagon"/>
<pad name="OUTB-2" x="-6.35" y="-5.08" drill="0.8" shape="octagon"/>
<pad name="OUTB-3" x="-6.35" y="-7.62" drill="0.8" shape="octagon"/>
<pad name="OUTA-2" x="-6.35" y="-10.16" drill="0.8" shape="octagon"/>
<pad name="OUTA-3" x="-6.35" y="-12.7" drill="0.8" shape="octagon"/>
</package>
</packages>
<symbols>
<symbol name="MOTORSHIELD">
<description>VNH5019 Motor Driver Carrier</description>
<wire x1="2.54" y1="15.24" x2="2.54" y2="-12.7" width="0.254" layer="94"/>
<wire x1="2.54" y1="-12.7" x2="20.32" y2="-12.7" width="0.254" layer="94"/>
<wire x1="20.32" y1="-12.7" x2="20.32" y2="-10.16" width="0.254" layer="94"/>
<wire x1="20.32" y1="-10.16" x2="20.32" y2="12.7" width="0.254" layer="94"/>
<wire x1="20.32" y1="12.7" x2="20.32" y2="15.24" width="0.254" layer="94"/>
<wire x1="20.32" y1="15.24" x2="2.54" y2="15.24" width="0.254" layer="94"/>
<pin name="VMOT" x="25.4" y="7.62" length="middle" direction="sup" rot="R180"/>
<pin name="GNDM" x="25.4" y="-5.08" length="middle" direction="sup" rot="R180"/>
<pin name="ENA/DIAGA" x="-2.54" y="-7.62" length="middle"/>
<pin name="PWM" x="-2.54" y="-5.08" length="middle" direction="in"/>
<pin name="CS" x="-2.54" y="-2.54" length="middle" direction="out"/>
<pin name="ENB/DIAGB" x="-2.54" y="0" length="middle"/>
<pin name="INB" x="-2.54" y="2.54" length="middle" direction="in"/>
<pin name="VDD" x="-2.54" y="5.08" length="middle" direction="sup"/>
<pin name="GND2" x="-2.54" y="7.62" length="middle" direction="sup"/>
<pin name="VOUT" x="-2.54" y="10.16" length="middle" direction="sup"/>
<pin name="GND" x="-2.54" y="12.7" length="middle" direction="sup"/>
<pin name="INA" x="-2.54" y="-10.16" length="middle" direction="in"/>
<text x="5.08" y="17.78" size="1.27" layer="95">&gt;NAME</text>
<text x="5.08" y="-15.24" size="1.27" layer="96">&gt;VALUE</text>
<pin name="INMOT2" x="25.4" y="-10.16" length="middle" direction="sup" rot="R180"/>
<pin name="INMOT1" x="25.4" y="12.7" length="middle" direction="sup" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VHN5019">
<description>Operating voltage: 5.5 – 24 V1&lt;BR&gt;
Output current: 12 A continuous (30 maximum)&lt;BR&gt;
3V-compatible inputs&lt;BR&gt;
PWM operation up to 20 kHz, which is ultrasonic and allows for quieter motor operation&lt;BR&gt;
Current sense output proportional to motor current (approx. 140 mV/A)&lt;BR&gt;
Motor indicator LEDs (indicates what the outputs are doing even when no motor is connected)&lt;BR&gt;
Robust:&lt;BR&gt;
Reverse-voltage protection&lt;BR&gt;
Can survive input voltages up to 41 V&lt;BR&gt;
Undervoltage and overvoltage shutdown&lt;BR&gt;
High-side and low-side thermal shutdown&lt;BR&gt;
Short-to-ground and short-to-Vcc protection&lt;BR&gt;</description>
<gates>
<gate name="G$1" symbol="MOTORSHIELD" x="-2.54" y="15.24"/>
</gates>
<devices>
<device name="" package="MOTOR-SHIELD">
<connects>
<connect gate="G$1" pin="CS" pad="CS"/>
<connect gate="G$1" pin="ENA/DIAGA" pad="ENA/DIAGA"/>
<connect gate="G$1" pin="ENB/DIAGB" pad="ENB/DIAGB"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND2" pad="GND2"/>
<connect gate="G$1" pin="GNDM" pad="GNDMOT-1"/>
<connect gate="G$1" pin="INA" pad="INA"/>
<connect gate="G$1" pin="INB" pad="INB"/>
<connect gate="G$1" pin="INMOT1" pad="INMOT1"/>
<connect gate="G$1" pin="INMOT2" pad="INMOT2"/>
<connect gate="G$1" pin="PWM" pad="PWM"/>
<connect gate="G$1" pin="VDD" pad="VDD"/>
<connect gate="G$1" pin="VMOT" pad="VMOT-1"/>
<connect gate="G$1" pin="VOUT" pad="VOUT"/>
</connects>
<technologies>
<technology name="">
<attribute name="MOTOR" value="motor" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="74xx-eu" urn="urn:adsk.eagle:library:85">
<description>&lt;b&gt;TTL Devices, 74xx Series with European Symbols&lt;/b&gt;&lt;p&gt;
Based on the following sources:
&lt;ul&gt;
&lt;li&gt;Texas Instruments &lt;i&gt;TTL Data Book&lt;/i&gt;&amp;nbsp;&amp;nbsp;&amp;nbsp;Volume 1, 1996.
&lt;li&gt;TTL Data Book, Volume 2 , 1993
&lt;li&gt;National Seminconductor Databook 1990, ALS/LS Logic
&lt;li&gt;ttl 74er digital data dictionary, ECA Electronic + Acustic GmbH, ISBN 3-88109-032-0
&lt;li&gt;http://icmaster.com/ViewCompare.asp
&lt;/ul&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="DIL14" urn="urn:adsk.eagle:footprint:1631/1" library_version="1">
<description>&lt;b&gt;Dual In Line Package&lt;/b&gt;</description>
<wire x1="8.89" y1="2.921" x2="-8.89" y2="2.921" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-2.921" x2="8.89" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="8.89" y1="2.921" x2="8.89" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="2.921" x2="-8.89" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-2.921" x2="-8.89" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="1.016" x2="-8.89" y2="-1.016" width="0.1524" layer="21" curve="-180"/>
<pad name="1" x="-7.62" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-5.08" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="7.62" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="8" x="7.62" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="-2.54" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="0" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="5.08" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="2.54" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="9" x="5.08" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="10" x="2.54" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="11" x="0" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="12" x="-2.54" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="13" x="-5.08" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="14" x="-7.62" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<text x="-9.271" y="-3.048" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="-6.731" y="-0.635" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="SO14" urn="urn:adsk.eagle:footprint:1630/1" library_version="1">
<description>&lt;b&gt;Small Outline package&lt;/b&gt; 150 mil</description>
<wire x1="4.064" y1="1.9558" x2="-4.064" y2="1.9558" width="0.1524" layer="51"/>
<wire x1="4.064" y1="-1.9558" x2="4.445" y2="-1.5748" width="0.1524" layer="21" curve="90"/>
<wire x1="-4.445" y1="1.5748" x2="-4.064" y2="1.9558" width="0.1524" layer="21" curve="-90"/>
<wire x1="4.064" y1="1.9558" x2="4.445" y2="1.5748" width="0.1524" layer="21" curve="-90"/>
<wire x1="-4.445" y1="-1.5748" x2="-4.064" y2="-1.9558" width="0.1524" layer="21" curve="90"/>
<wire x1="-4.064" y1="-1.9558" x2="4.064" y2="-1.9558" width="0.1524" layer="51"/>
<wire x1="4.445" y1="-1.5748" x2="4.445" y2="1.5748" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.5748" x2="-4.445" y2="0.508" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="0.508" x2="-4.445" y2="-0.508" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-0.508" x2="-4.445" y2="-1.5748" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="0.508" x2="-4.445" y2="-0.508" width="0.1524" layer="21" curve="-180"/>
<wire x1="-4.445" y1="-1.6002" x2="4.445" y2="-1.6002" width="0.0508" layer="21"/>
<smd name="1" x="-3.81" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="14" x="-3.81" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="2" x="-2.54" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="3" x="-1.27" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="13" x="-2.54" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="12" x="-1.27" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="4" x="0" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="11" x="0" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="5" x="1.27" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="6" x="2.54" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="10" x="1.27" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="9" x="2.54" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="7" x="3.81" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="8" x="3.81" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<text x="-3.175" y="-0.762" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="-4.826" y="-1.905" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<rectangle x1="-0.254" y1="1.9558" x2="0.254" y2="3.0988" layer="51"/>
<rectangle x1="-4.064" y1="-3.0988" x2="-3.556" y2="-1.9558" layer="51"/>
<rectangle x1="-2.794" y1="-3.0988" x2="-2.286" y2="-1.9558" layer="51"/>
<rectangle x1="-1.524" y1="-3.0734" x2="-1.016" y2="-1.9304" layer="51"/>
<rectangle x1="-0.254" y1="-3.0988" x2="0.254" y2="-1.9558" layer="51"/>
<rectangle x1="-1.524" y1="1.9558" x2="-1.016" y2="3.0988" layer="51"/>
<rectangle x1="-2.794" y1="1.9558" x2="-2.286" y2="3.0988" layer="51"/>
<rectangle x1="-4.064" y1="1.9558" x2="-3.556" y2="3.0988" layer="51"/>
<rectangle x1="1.016" y1="1.9558" x2="1.524" y2="3.0988" layer="51"/>
<rectangle x1="2.286" y1="1.9558" x2="2.794" y2="3.0988" layer="51"/>
<rectangle x1="3.556" y1="1.9558" x2="4.064" y2="3.0988" layer="51"/>
<rectangle x1="1.016" y1="-3.0988" x2="1.524" y2="-1.9558" layer="51"/>
<rectangle x1="2.286" y1="-3.0988" x2="2.794" y2="-1.9558" layer="51"/>
<rectangle x1="3.556" y1="-3.0988" x2="4.064" y2="-1.9558" layer="51"/>
</package>
<package name="LCC20" urn="urn:adsk.eagle:footprint:1641/1" library_version="1">
<description>&lt;b&gt;Leadless Chip Carrier&lt;/b&gt;&lt;p&gt; Ceramic Package</description>
<wire x1="-0.4001" y1="4.4" x2="-0.87" y2="4.4" width="0.2032" layer="51"/>
<wire x1="-3.3" y1="4.4" x2="-4.4" y2="3.3" width="0.2032" layer="51"/>
<wire x1="-0.4001" y1="4.3985" x2="0.4001" y2="4.3985" width="0.2032" layer="51" curve="180"/>
<wire x1="-1.6701" y1="4.3985" x2="-0.8699" y2="4.3985" width="0.2032" layer="51" curve="180"/>
<wire x1="-4.3985" y1="2.14" x2="-4.3985" y2="2.94" width="0.2032" layer="51" curve="180"/>
<wire x1="-2.9401" y1="4.4" x2="-3.3" y2="4.4" width="0.2032" layer="51"/>
<wire x1="0.87" y1="4.4" x2="0.4001" y2="4.4" width="0.2032" layer="51"/>
<wire x1="0.87" y1="4.3985" x2="1.67" y2="4.3985" width="0.2032" layer="51" curve="180"/>
<wire x1="-4.4" y1="3.3" x2="-4.4" y2="2.9401" width="0.2032" layer="51"/>
<wire x1="-4.4" y1="2.14" x2="-4.4" y2="1.6701" width="0.2032" layer="51"/>
<wire x1="-4.3985" y1="0.87" x2="-4.3985" y2="1.67" width="0.2032" layer="51" curve="180"/>
<wire x1="-4.3985" y1="-0.4001" x2="-4.3985" y2="0.4001" width="0.2032" layer="51" curve="180"/>
<wire x1="-4.3985" y1="-1.6701" x2="-4.3985" y2="-0.8699" width="0.2032" layer="51" curve="180"/>
<wire x1="-4.4" y1="0.87" x2="-4.4" y2="0.4001" width="0.2032" layer="51"/>
<wire x1="-4.4" y1="-0.4001" x2="-4.4" y2="-0.87" width="0.2032" layer="51"/>
<wire x1="-4.4" y1="-2.9401" x2="-4.4" y2="-4.4" width="0.2032" layer="51"/>
<wire x1="-4.4" y1="-4.4" x2="-4.4" y2="-4.4099" width="0.2032" layer="51"/>
<wire x1="2.14" y1="4.3985" x2="2.94" y2="4.3985" width="0.2032" layer="51" curve="180"/>
<wire x1="2.14" y1="4.4" x2="1.6701" y2="4.4" width="0.2032" layer="51"/>
<wire x1="4.4" y1="4.4" x2="2.9401" y2="4.4" width="0.2032" layer="51"/>
<wire x1="0.4001" y1="-4.4" x2="0.87" y2="-4.4" width="0.2032" layer="51"/>
<wire x1="-0.4001" y1="-4.3985" x2="0.4001" y2="-4.3985" width="0.2032" layer="51" curve="-180"/>
<wire x1="0.87" y1="-4.3985" x2="1.67" y2="-4.3985" width="0.2032" layer="51" curve="-180"/>
<wire x1="2.9401" y1="-4.4" x2="4.4" y2="-4.4" width="0.2032" layer="51"/>
<wire x1="-0.87" y1="-4.4" x2="-0.4001" y2="-4.4" width="0.2032" layer="51"/>
<wire x1="-1.6701" y1="-4.3985" x2="-0.8699" y2="-4.3985" width="0.2032" layer="51" curve="-180"/>
<wire x1="-2.9401" y1="-4.3985" x2="-2.1399" y2="-4.3985" width="0.2032" layer="51" curve="-180"/>
<wire x1="-2.14" y1="-4.4" x2="-1.6701" y2="-4.4" width="0.2032" layer="51"/>
<wire x1="-4.4" y1="-4.4" x2="-2.9401" y2="-4.4" width="0.2032" layer="51"/>
<wire x1="4.4" y1="0.4001" x2="4.4" y2="0.87" width="0.2032" layer="51"/>
<wire x1="4.3985" y1="0.4001" x2="4.3985" y2="-0.4001" width="0.2032" layer="51" curve="180"/>
<wire x1="4.3985" y1="1.6701" x2="4.3985" y2="0.8699" width="0.2032" layer="51" curve="180"/>
<wire x1="4.4" y1="2.9401" x2="4.4" y2="4.4" width="0.2032" layer="51"/>
<wire x1="4.4" y1="-0.87" x2="4.4" y2="-0.4001" width="0.2032" layer="51"/>
<wire x1="4.3985" y1="-0.87" x2="4.3985" y2="-1.67" width="0.2032" layer="51" curve="180"/>
<wire x1="4.3985" y1="-2.14" x2="4.3985" y2="-2.94" width="0.2032" layer="51" curve="180"/>
<wire x1="4.4" y1="-2.14" x2="4.4" y2="-1.6701" width="0.2032" layer="51"/>
<wire x1="4.4" y1="-4.4" x2="4.4" y2="-2.9401" width="0.2032" layer="51"/>
<wire x1="-2.9401" y1="4.3985" x2="-2.1399" y2="4.3985" width="0.2032" layer="51" curve="180"/>
<wire x1="-1.6701" y1="4.4" x2="-2.14" y2="4.4" width="0.2032" layer="51"/>
<wire x1="-4.3985" y1="-2.9401" x2="-4.3985" y2="-2.1399" width="0.2032" layer="51" curve="180"/>
<wire x1="-4.4" y1="-1.6701" x2="-4.4" y2="-2.14" width="0.2032" layer="51"/>
<wire x1="1.6701" y1="-4.4" x2="2.14" y2="-4.4" width="0.2032" layer="51"/>
<wire x1="2.14" y1="-4.3985" x2="2.94" y2="-4.3985" width="0.2032" layer="51" curve="-180"/>
<wire x1="4.3985" y1="2.9401" x2="4.3985" y2="2.1399" width="0.2032" layer="51" curve="180"/>
<wire x1="4.4" y1="1.6701" x2="4.4" y2="2.14" width="0.2032" layer="51"/>
<wire x1="-3.3" y1="4.4" x2="-4.4" y2="3.3" width="0.2032" layer="21"/>
<wire x1="-4.4" y1="-3.1941" x2="-4.4" y2="-4.4" width="0.2032" layer="21"/>
<wire x1="-4.4" y1="-4.4" x2="-3.1941" y2="-4.4" width="0.2032" layer="21"/>
<wire x1="3.1941" y1="-4.4" x2="4.4" y2="-4.4" width="0.2032" layer="21"/>
<wire x1="4.4" y1="-4.4" x2="4.4" y2="-3.1941" width="0.2032" layer="21"/>
<wire x1="4.4" y1="3.1941" x2="4.4" y2="4.4" width="0.2032" layer="21"/>
<wire x1="4.4" y1="4.4" x2="3.1941" y2="4.4" width="0.2032" layer="21"/>
<smd name="2" x="-1.27" y="4.5001" dx="0.8" dy="2" layer="1"/>
<smd name="1" x="0" y="3.8001" dx="0.8" dy="3.4" layer="1"/>
<smd name="3" x="-2.54" y="4.5001" dx="0.8" dy="2" layer="1"/>
<smd name="4" x="-4.5001" y="2.54" dx="2" dy="0.8" layer="1"/>
<smd name="5" x="-4.5001" y="1.27" dx="2" dy="0.8" layer="1"/>
<smd name="6" x="-4.5001" y="0" dx="2" dy="0.8" layer="1"/>
<smd name="7" x="-4.5001" y="-1.27" dx="2" dy="0.8" layer="1"/>
<smd name="8" x="-4.5001" y="-2.54" dx="2" dy="0.8" layer="1"/>
<smd name="9" x="-2.54" y="-4.5001" dx="0.8" dy="2" layer="1"/>
<smd name="10" x="-1.27" y="-4.5001" dx="0.8" dy="2" layer="1"/>
<smd name="11" x="0" y="-4.5001" dx="0.8" dy="2" layer="1"/>
<smd name="12" x="1.27" y="-4.5001" dx="0.8" dy="2" layer="1"/>
<smd name="13" x="2.54" y="-4.5001" dx="0.8" dy="2" layer="1"/>
<smd name="14" x="4.5001" y="-2.54" dx="2" dy="0.8" layer="1"/>
<smd name="15" x="4.5001" y="-1.27" dx="2" dy="0.8" layer="1"/>
<smd name="16" x="4.5001" y="0" dx="2" dy="0.8" layer="1"/>
<smd name="17" x="4.5001" y="1.27" dx="2" dy="0.8" layer="1"/>
<smd name="18" x="4.5001" y="2.54" dx="2" dy="0.8" layer="1"/>
<smd name="19" x="2.54" y="4.5001" dx="0.8" dy="2" layer="1"/>
<smd name="20" x="1.27" y="4.5001" dx="0.8" dy="2" layer="1"/>
<text x="-4.0051" y="6.065" size="1.778" layer="25">&gt;NAME</text>
<text x="-3.9751" y="-7.5601" size="1.778" layer="27">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="DIL14" urn="urn:adsk.eagle:package:2008/1" type="box" library_version="1">
<description>Dual In Line Package</description>
</package3d>
<package3d name="SO14" urn="urn:adsk.eagle:package:2007/1" type="box" library_version="1">
<description>Small Outline package 150 mil</description>
</package3d>
<package3d name="LCC20" urn="urn:adsk.eagle:package:2012/1" type="box" library_version="1">
<description>Leadless Chip Carrier Ceramic Package</description>
</package3d>
</packages3d>
<symbols>
<symbol name="7404" urn="urn:adsk.eagle:symbol:1629/1" library_version="1">
<wire x1="-5.08" y1="5.08" x2="5.08" y2="0" width="0.4064" layer="94"/>
<wire x1="5.08" y1="0" x2="-5.08" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="-5.08" y1="-5.08" x2="-5.08" y2="5.08" width="0.4064" layer="94"/>
<text x="2.54" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="2.54" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="I" x="-10.16" y="0" visible="pad" length="middle" direction="in"/>
<pin name="O" x="10.16" y="0" visible="pad" length="middle" direction="out" function="dot" rot="R180"/>
</symbol>
<symbol name="PWRN" urn="urn:adsk.eagle:symbol:1632/1" library_version="1">
<text x="-0.635" y="-0.635" size="1.778" layer="95">&gt;NAME</text>
<text x="1.905" y="-5.842" size="1.27" layer="95" rot="R90">GND</text>
<text x="1.905" y="2.54" size="1.27" layer="95" rot="R90">VCC</text>
<pin name="GND" x="0" y="-7.62" visible="pad" length="middle" direction="pwr" rot="R90"/>
<pin name="VCC" x="0" y="7.62" visible="pad" length="middle" direction="pwr" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="74*04" urn="urn:adsk.eagle:component:2139/1" prefix="IC" library_version="1">
<description>Hex &lt;b&gt;INVERTER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="7404" x="17.78" y="0" swaplevel="1"/>
<gate name="B" symbol="7404" x="17.78" y="-12.7" swaplevel="1"/>
<gate name="C" symbol="7404" x="17.78" y="-25.4" swaplevel="1"/>
<gate name="D" symbol="7404" x="45.72" y="0" swaplevel="1"/>
<gate name="E" symbol="7404" x="45.72" y="-12.7" swaplevel="1"/>
<gate name="F" symbol="7404" x="45.72" y="-25.4" swaplevel="1"/>
<gate name="P" symbol="PWRN" x="-5.08" y="-10.16" addlevel="request"/>
</gates>
<devices>
<device name="N" package="DIL14">
<connects>
<connect gate="A" pin="I" pad="1"/>
<connect gate="A" pin="O" pad="2"/>
<connect gate="B" pin="I" pad="3"/>
<connect gate="B" pin="O" pad="4"/>
<connect gate="C" pin="I" pad="5"/>
<connect gate="C" pin="O" pad="6"/>
<connect gate="D" pin="I" pad="9"/>
<connect gate="D" pin="O" pad="8"/>
<connect gate="E" pin="I" pad="11"/>
<connect gate="E" pin="O" pad="10"/>
<connect gate="F" pin="I" pad="13"/>
<connect gate="F" pin="O" pad="12"/>
<connect gate="P" pin="GND" pad="7"/>
<connect gate="P" pin="VCC" pad="14"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:2008/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
<technology name="AC"/>
<technology name="ACT"/>
<technology name="ALS"/>
<technology name="AS"/>
<technology name="HC"/>
<technology name="HCT"/>
<technology name="LS"/>
<technology name="S"/>
</technologies>
</device>
<device name="D" package="SO14">
<connects>
<connect gate="A" pin="I" pad="1"/>
<connect gate="A" pin="O" pad="2"/>
<connect gate="B" pin="I" pad="3"/>
<connect gate="B" pin="O" pad="4"/>
<connect gate="C" pin="I" pad="5"/>
<connect gate="C" pin="O" pad="6"/>
<connect gate="D" pin="I" pad="9"/>
<connect gate="D" pin="O" pad="8"/>
<connect gate="E" pin="I" pad="11"/>
<connect gate="E" pin="O" pad="10"/>
<connect gate="F" pin="I" pad="13"/>
<connect gate="F" pin="O" pad="12"/>
<connect gate="P" pin="GND" pad="7"/>
<connect gate="P" pin="VCC" pad="14"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:2007/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
<technology name="AC"/>
<technology name="ACT"/>
<technology name="ALS"/>
<technology name="AS"/>
<technology name="HC"/>
<technology name="HCT"/>
<technology name="LS"/>
<technology name="S"/>
</technologies>
</device>
<device name="FK" package="LCC20">
<connects>
<connect gate="A" pin="I" pad="2"/>
<connect gate="A" pin="O" pad="3"/>
<connect gate="B" pin="I" pad="4"/>
<connect gate="B" pin="O" pad="6"/>
<connect gate="C" pin="I" pad="8"/>
<connect gate="C" pin="O" pad="9"/>
<connect gate="D" pin="I" pad="13"/>
<connect gate="D" pin="O" pad="12"/>
<connect gate="E" pin="I" pad="16"/>
<connect gate="E" pin="O" pad="14"/>
<connect gate="F" pin="I" pad="19"/>
<connect gate="F" pin="O" pad="18"/>
<connect gate="P" pin="GND" pad="10"/>
<connect gate="P" pin="VCC" pad="20"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:2012/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
<technology name="AC"/>
<technology name="ACT"/>
<technology name="HC"/>
<technology name="HCT"/>
<technology name="LS"/>
<technology name="S"/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="libreria valerio">
<packages>
<package name="REGOLATORE-3.3V-1A">
<wire x1="12.7" y1="0" x2="12.7" y2="17.78" width="0.127" layer="21"/>
<wire x1="12.7" y1="17.78" x2="0" y2="17.78" width="0.127" layer="21"/>
<wire x1="12.7" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
<wire x1="0" y1="0" x2="0" y2="17.78" width="0.127" layer="21"/>
<pad name="PG" x="1.27" y="1.27" drill="1"/>
<pad name="SHDN" x="3.81" y="1.27" drill="1"/>
<pad name="VIN" x="6.35" y="1.27" drill="1"/>
<pad name="VOUT" x="11.43" y="1.27" drill="1"/>
<pad name="GND" x="8.89" y="1.27" drill="1" shape="square"/>
</package>
</packages>
<symbols>
<symbol name="REGOLATORE-3.3V-1A">
<wire x1="10.16" y1="7.62" x2="-7.62" y2="7.62" width="0.254" layer="94"/>
<wire x1="-7.62" y1="7.62" x2="-7.62" y2="-7.62" width="0.254" layer="94"/>
<pin name="PG" x="5.08" y="12.7" length="middle" rot="R270"/>
<pin name="SHDN" x="-5.08" y="12.7" length="middle" rot="R270"/>
<pin name="VIN" x="-12.7" y="-2.54" length="middle"/>
<pin name="GND" x="0" y="-12.7" length="middle" rot="R90"/>
<pin name="VOUT" x="15.24" y="-2.54" length="middle" rot="R180"/>
<wire x1="10.16" y1="7.62" x2="10.16" y2="-7.62" width="0.254" layer="94"/>
<wire x1="10.16" y1="-7.62" x2="-7.62" y2="-7.62" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="REGOLATORE-3.3V-1A">
<description>regolatore di tensione da 12V a 3,3 V</description>
<gates>
<gate name="G$1" symbol="REGOLATORE-3.3V-1A" x="-5.08" y="0"/>
</gates>
<devices>
<device name="" package="REGOLATORE-3.3V-1A">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="PG" pad="PG"/>
<connect gate="G$1" pin="SHDN" pad="SHDN"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
<connect gate="G$1" pin="VOUT" pad="VOUT"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="Teensy_3_and_LC_Series_Boards_v1.4" deviceset="TEENSY_3.1-3.2_ALL_PINS&amp;PADS" device=""/>
<part name="U$2" library="VHN5019" deviceset="VHN5019" device=""/>
<part name="U$3" library="VHN5019" deviceset="VHN5019" device=""/>
<part name="U$4" library="VHN5019" deviceset="VHN5019" device=""/>
<part name="U$5" library="VHN5019" deviceset="VHN5019" device=""/>
<part name="IC1" library="74xx-eu" library_urn="urn:adsk.eagle:library:85" deviceset="74*04" device="N" package3d_urn="urn:adsk.eagle:package:2008/1"/>
<part name="U$6" library="libreria valerio" deviceset="REGOLATORE-3.3V-1A" device=""/>
<part name="U$7" library="libreria valerio" deviceset="REGOLATORE-3.3V-1A" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<wire x1="223.52" y1="200.66" x2="-27.94" y2="200.66" width="0.4064" layer="96" style="longdash"/>
<wire x1="-27.94" y1="200.66" x2="-27.94" y2="27.94" width="0.4064" layer="96" style="longdash"/>
<wire x1="-27.94" y1="27.94" x2="223.52" y2="27.94" width="0.4064" layer="96" style="longdash"/>
<wire x1="223.52" y1="200.66" x2="223.52" y2="27.94" width="0.4064" layer="96" style="longdash"/>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="104.14" y="114.3"/>
<instance part="U$2" gate="G$1" x="25.4" y="165.1"/>
<instance part="U$3" gate="G$1" x="25.4" y="63.5"/>
<instance part="U$4" gate="G$1" x="182.88" y="167.64"/>
<instance part="U$5" gate="G$1" x="187.96" y="63.5"/>
<instance part="IC1" gate="A" x="2.54" y="66.04"/>
<instance part="IC1" gate="B" x="165.1" y="66.04"/>
<instance part="IC1" gate="C" x="160.02" y="170.18"/>
<instance part="IC1" gate="D" x="5.08" y="167.64"/>
<instance part="U$6" gate="G$1" x="180.34" y="121.92"/>
<instance part="U$7" gate="G$1" x="20.32" y="124.46"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="INB"/>
<pinref part="IC1" gate="A" pin="O"/>
<wire x1="22.86" y1="66.04" x2="12.7" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="INB"/>
<pinref part="IC1" gate="B" pin="O"/>
<wire x1="185.42" y1="66.04" x2="175.26" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="INB"/>
<pinref part="IC1" gate="D" pin="O"/>
<wire x1="22.86" y1="167.64" x2="15.24" y2="167.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="IC1" gate="C" pin="O"/>
<pinref part="U$4" gate="G$1" pin="INB"/>
<wire x1="170.18" y1="170.18" x2="180.34" y2="170.18" width="0.1524" layer="91"/>
</segment>
</net>
<net name="PWM3" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="6/PWM"/>
<wire x1="81.28" y1="127" x2="73.66" y2="127" width="0.1524" layer="91"/>
<label x="73.66" y="127" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="PWM2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="20/A6/PWM"/>
<wire x1="81.28" y1="91.44" x2="73.66" y2="91.44" width="0.1524" layer="91"/>
<label x="73.66" y="91.44" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="PWM1" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="22/A8/T/PWM"/>
<wire x1="81.28" y1="86.36" x2="73.66" y2="86.36" width="0.1524" layer="91"/>
<label x="73.66" y="86.36" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="DIR4" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="11/MOSI"/>
<wire x1="81.28" y1="114.3" x2="73.66" y2="114.3" width="0.1524" layer="91"/>
<label x="73.66" y="114.3" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="INA"/>
<pinref part="IC1" gate="D" pin="I"/>
<wire x1="22.86" y1="154.94" x2="-5.08" y2="154.94" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="154.94" x2="-5.08" y2="167.64" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="167.64" x2="-10.16" y2="167.64" width="0.1524" layer="91"/>
<junction x="-5.08" y="167.64"/>
<label x="-10.16" y="167.64" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="DIR3" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="12/MISO"/>
<wire x1="81.28" y1="111.76" x2="73.66" y2="111.76" width="0.1524" layer="91"/>
<label x="73.66" y="111.76" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="IC1" gate="A" pin="I"/>
<pinref part="U$3" gate="G$1" pin="INA"/>
<wire x1="-7.62" y1="66.04" x2="-7.62" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="53.34" x2="22.86" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="66.04" x2="-12.7" y2="66.04" width="0.1524" layer="91"/>
<junction x="-7.62" y="66.04"/>
<label x="-12.7" y="66.04" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="DIR2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="14/A0"/>
<wire x1="81.28" y1="106.68" x2="73.66" y2="106.68" width="0.1524" layer="91"/>
<label x="73.66" y="106.68" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$5" gate="G$1" pin="INA"/>
<pinref part="IC1" gate="B" pin="I"/>
<wire x1="185.42" y1="53.34" x2="154.94" y2="53.34" width="0.1524" layer="91"/>
<wire x1="154.94" y1="53.34" x2="154.94" y2="66.04" width="0.1524" layer="91"/>
<wire x1="154.94" y1="66.04" x2="147.32" y2="66.04" width="0.1524" layer="91"/>
<junction x="154.94" y="66.04"/>
<label x="147.32" y="66.04" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="DIR1" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="15/A1/T"/>
<wire x1="81.28" y1="104.14" x2="73.66" y2="104.14" width="0.1524" layer="91"/>
<label x="73.66" y="104.14" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="INA"/>
<pinref part="IC1" gate="C" pin="I"/>
<wire x1="180.34" y1="157.48" x2="149.86" y2="157.48" width="0.1524" layer="91"/>
<wire x1="149.86" y1="157.48" x2="149.86" y2="170.18" width="0.1524" layer="91"/>
<wire x1="149.86" y1="170.18" x2="144.78" y2="170.18" width="0.1524" layer="91"/>
<junction x="149.86" y="170.18"/>
<label x="144.78" y="170.18" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND"/>
<wire x1="127" y1="134.62" x2="132.08" y2="134.62" width="0.1524" layer="91"/>
<label x="132.08" y="134.62" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="GND"/>
<wire x1="22.86" y1="177.8" x2="17.78" y2="177.8" width="0.1524" layer="91"/>
<label x="17.78" y="177.8" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="GND"/>
<wire x1="180.34" y1="180.34" x2="175.26" y2="180.34" width="0.1524" layer="91"/>
<label x="175.26" y="180.34" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$5" gate="G$1" pin="GND"/>
<wire x1="185.42" y1="76.2" x2="180.34" y2="76.2" width="0.1524" layer="91"/>
<label x="180.34" y="76.2" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$3" gate="G$1" pin="GND"/>
<wire x1="22.86" y1="76.2" x2="17.78" y2="76.2" width="0.1524" layer="91"/>
<label x="17.78" y="76.2" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$6" gate="G$1" pin="GND"/>
<wire x1="180.34" y1="109.22" x2="180.34" y2="106.68" width="0.1524" layer="91"/>
<label x="180.34" y="106.68" size="1.778" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$7" gate="G$1" pin="GND"/>
<wire x1="20.32" y1="111.76" x2="20.32" y2="109.22" width="0.1524" layer="91"/>
<label x="20.32" y="109.22" size="1.778" layer="95" rot="R270" xref="yes"/>
</segment>
</net>
<net name="3.3V" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="3.3V"/>
<wire x1="127" y1="139.7" x2="132.08" y2="139.7" width="0.1524" layer="91"/>
<label x="132.08" y="139.7" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U$6" gate="G$1" pin="VOUT"/>
<wire x1="195.58" y1="119.38" x2="200.66" y2="119.38" width="0.1524" layer="91"/>
<label x="200.66" y="119.38" size="1.778" layer="95" xref="yes"/>
</segment>
</net>
<net name="12V" class="0">
<segment>
<pinref part="U$6" gate="G$1" pin="VIN"/>
<wire x1="167.64" y1="119.38" x2="162.56" y2="119.38" width="0.1524" layer="91"/>
<label x="162.56" y="119.38" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$7" gate="G$1" pin="VIN"/>
<wire x1="7.62" y1="121.92" x2="2.54" y2="121.92" width="0.1524" layer="91"/>
<label x="2.54" y="121.92" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="5V" class="0">
<segment>
<pinref part="U$7" gate="G$1" pin="VOUT"/>
<wire x1="35.56" y1="121.92" x2="40.64" y2="121.92" width="0.1524" layer="91"/>
<label x="40.64" y="121.92" size="1.778" layer="95" xref="yes"/>
</segment>
</net>
<net name="PWM4" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="9/RX2/PWM"/>
<wire x1="81.28" y1="119.38" x2="73.66" y2="119.38" width="0.1524" layer="91"/>
<label x="73.66" y="119.38" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
