# Start-Up Sequence Circuit

# Overview
We designed this circuit for the SAE E-BAJA 2023 competetion. The circuit follows the rules and regulation of the SAE rulebook published in 2022 and 2023. The E-BAJA power circuit comprises of two parts, HV circuit and LV circuit. The synthesis and ana;ysi of the LV circuit is more adapblte and mangeable as per the undergraduate level, however for HV circuit there is hardly any re-designing and struturing of the systems are possible. Since, the HV circuit includes, motor (PMSM/BLDC), motor driver block, HV circuit breaker, battery accumulator, HV harness. The connections of these HV circuits were predefined from the manufacures/suppliers. We could design and fabracrate an accumulator from the scratch but that is a diiferent area and is not a part this project. 

The LV circuit is the most manageable and flexible part where our most of the electrical engineering worked. There is no inclusive circuitory rule for the synthesis and analysis of the circuits but there were few exclusive rules given SAE INDIA rulebook. The rules for the start up of the vehicle must be followed.

1. Vehicle Controls
1.1. Brakes: Any brakes, when actuated, shall cause the brake light to illuminate.
Brake lights shall operate regardless of the kill switch setting and shall always be powered and functional all the time.
1.2. Throttle: The throttle pedal shall actuate a throttle cable.
1.3. Reverse Light: The reverse light shall illuminate when the vehicle is shifted to reverse gear and is extinguished when the vehicle is shifted out of reverse gear. The wattage of Reverse light bulbs should be as per AIS standard.
1.4. Reverse Alarm: Vehicles with reverse gear shall be equipped with an audible reverse alarm. The reverse alarm shall sound when the vehicle is shifted to reverse gear and silenced when the vehicle is shifted out of reverse gear.    
1.5. DC-DC Converter: An HV-rated cut-off switch is mandatory and should be present between the tractive system Accumulator(s) DC-DC and the Converter. 
1.6. Ignition Switch: An HV-rated cut-off switch is mandatory and should be present between the tractive system Accumulator(s) and the DC-DC Converter. 
1.7. HV rated cut-off switch: An HV-rated cut-off switch is mandatory and should be present between the tractive system Accumulator(s) and the DC-DC Converter. 
1.8. Kill Switches: The Kill switch must de-energize the Tractive system, AIR, and TSAL, may de-energize the reverse light, and reverse alarm but shall not de-energize the Brake Light when pressed. Brake lights shall operate regardless of setting and shall always be powered and functional as long as the HV-rated cut-off switch and GLV ignition/master switch is on. 
1.9. Accelerator Pedal: Team shall use a Hall effect type throttle pedal in addition to the above-mentioned regulations

2. Battery Accumulator
2.1. Accumulators: The Tractive System Accumulator(s) pack shall include at least one AIR and one Fuse, which will open the circuit and disconnect the energy flow from Accumulator(s) to the remaining tractive system whenever a fault is detected. 
The Accumulator(s) isolation relays should isolate the Accumulator(s)s from the HV system and must be Normally Open type. The fuse protecting the Accumulator(s) tractive system circuit must have a rating lower than the maximum switch-off current of the isolation relays. The Accumulator(s) isolation relays should be provided to isolate the Accumulator(s)s from the Tractive system and must be “Normally Open Type”. 
The fuse for protecting the Accumulator(s) tractive system circuit must have a rating lower than the maximum peak current of the isolation relays. 
2.2.	Battery Management System:
2.2.1.	The BMS shall be powered by the tractive battery and shall continuously monitor the cells and pack at all times. 
2.2.2.	The BMS must feature Overvolt and Under volt protection, i.e., continuously measure the cell voltage of every cell, to keep the cell voltage levels (within the allowable minimum and maximum cell voltage) as stated in the cell data sheet. If individual cells are directly connected in parallel, only one voltage measurement is needed. 
2.2.3.	The BMS shall not be able to trigger the HV AIR when the Ignition or Kill Switch is in the off position. 
2.2.4.	Any GLV connection to the BMS must be isolated from the tractive system, including any connections to external devices such as laptops. 
2.2.5.	The temperature of the cells should be monitored and if the temperature exceeds the permissible battery temperature specification, BMS should shut down the system. 
2.2.6. The BMS shall feature overcurrent protection and short circuit protection, pack, cell, and BMS temperature i.e., continuously monitor the current/temperature and trigger a shutdown in the event of any abnormal behaviour. 
2.2.7.	Should the BMS fail, lose power, declare a critical error, or become in-operational, the BMS should shut down the system. 
2.2.8.	BMS must be rigidly fastened to sustain vibrations in dynamic conditions. 
2.2.9.	BMS should follow International Electro-Technical Commission (IEC) 60529 IP67 i.e., no dust and water entry, or be housed in a similarly rated casing. 
2.2.10.	Teams shall take the necessary care to ensure that the HV Accumulator(s) does not deep discharge during storage, idle as a result of the BMS’s operational consumption. 
2.3.	Activating The Tractive System: 
2.3.1.	The driver must be able to (re-)activate or reset the tractive system from within the cockpit without the assistance of any other person except for situations in which the BMS has shut down the tractive system. 
2.3.2.	The Tractive system should not be activated while charging is in progress. 
2.3.3.	The Tractive system should not be activated when kill switch(s) are pressed. 

2.4.	Ready To Drive Mode:
2.4.1. The gear/F-N-R switch must be in the neutral position. 
2.4.2.	The accelerator pedal shouldn’t be pressed /activated. 
2.4.3.	While pressing the brake pedal a dedicated start switch/button should be pressed.
After the kill switch has been engaged, the vehicle should exit the Ready-to-Drive-Mode. To activate/enter into Ready-to-Drive-Mode above process shall be followed. 

2.5. TSAL: TSAL should be continuously flashing when the Tractive system is in an active state (when the vehicle is in “Ready to Drive Mode”). A Tractive system is defined to be active, when the accumulator isolation relay is closed, and the energy is available to the tractive system. 
The TSAL must be a round beacon type and an amber flashing light (>350 Lumens per unit, IP65 rated) with a frequency of 2Hz-5Hz. 

2.6. RTDS: The vehicle must make a characteristic sound, be maintained at a minimum level of 70dB, fast weighting, in a radius of 2m around the vehicle, once but not continuous, for at least 1 second and a maximum of 3 seconds immediately after it is set in ready to drive mode every time. 

2.7. Driver Display: Tractive battery pack Voltage, Temperature, and State of Charge (SOC in %) shall be displayed (at all times) on the driver dashboard when the key is turned ON. 

For the LV circuit synthesis we have conisered 1, 2.3, 2.4, 2.5 and 2.6 as the boundary condary conditions. The rest of the points are already being taken care by the HV circuit design which is not the discussion of this project.

# Bill of materials used in the Proteus Simulation
<img width="469" height="320" alt="image" src="https://github.com/user-attachments/assets/da975697-aadd-42ce-8057-199274edf43e" />
Note: Fuses, switches, toggle switches and motor are the components that are assigned differently and are not part of BOM. Our main focus was to test the conditions of the circuit based on the rules provided by SAE e-BAJA.


<img width="831" height="661" alt="image" src="https://github.com/user-attachments/assets/30b446d4-53fd-4a79-ae9e-965b1f4245b1" />

