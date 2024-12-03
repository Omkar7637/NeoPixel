# **Scrolling Display Using NeoPixel LED Matrix**  

A project to create a scrolling LED display system using NeoPixel technology, controlled by an Atmega328P microcontroller. This system features customizable text displays, animations, and modular expansion capabilities, suitable for digital advertising, educational institutions, and public spaces.  

---

## **Introduction**  
Display advertising plays a critical role in marketing, with methods ranging from newspapers and posters to modern LED digital boards. This project implements a scrolling LED display using a 300-LED NeoPixel strip controlled by an AVR microcontroller. It provides durability, customization, and ease of use for both advertising and informational purposes.  

---

## **Literature Survey**  
- Surveyed existing LED-based advertising products and compared various technologies.  
- Analyzed advantages over traditional methods like glow signboards.  
- Referenced relevant journal papers, such as one from IEEE, highlighting the innovation and applicability of LED matrix displays.  

---

## **Specifications**  
### **Electrical Specifications**  
- **Power Supply**: 5V, 6.0A (maximum).  
- **Current Consumption**: 20mA per LED at full brightness, totaling 6.0A for 300 LEDs.  
- **Microcontroller**: Atmega328P.  

### **Mechanical Specifications**  
- **Dimensions**: Customizable based on the application.  
- **Enclosure Material**: Lightweight, durable materials for environmental compatibility.  

---

## **Block Diagram & Description**  
### **Key Functional Steps**:  
1. Power ON initializes the microcontroller with a fixed message scrolling on the LED matrix.  
2. Text messages are input via a USB-to-TTL converter and stored in the microcontroller's buffer.  
3. The microcontroller converts the text into a matrix format and displays it.  
4. Preloaded animations or static images can be stored and displayed.  
5. Uses FastLED library for precise LED control and animation creation.  

---

## **Hardware System Design**  
### **Block Design**:  
- **Power Supply Unit**: Provides stable 5V, 6.0A for LED operations.  
- **Controller Unit**: Atmega328P for message and animation control.  
- **Input Interface**: USB-to-TTL converter for programming and data input.  
- **LED Display**: NeoPixel 300-LED strip for vibrant scrolling displays.  

### **Circuit Diagram**  
- Complete circuit diagram is available in the documentation.  

---

## **Software System Design**  
### **Flowchart**:  
1. Initialize hardware and peripherals.  
2. Read message input via USB-to-TTL converter.  
3. Convert text to matrix format.  
4. Display the message or animation on the NeoPixel LED strip.  
5. Repeat or await new input.  

### **Libraries Used**:  
- **FastLED**: For LED control and animations.  

---

## **Enclosure Design**  
- The enclosure is designed for portability and durability.  
- Materials: Lightweight, heat-resistant plastic.  
- Includes front panel for easy message visibility.  

---

## **Results and Discussion**  
- Snapshots of the scrolling LED display with sample text.  
- Graphical representation of power consumption vs. brightness levels.  
- Demonstrated modularity and responsiveness of the system.  

---

## **Getting Started**  
1. **Hardware Setup**: Assemble the NeoPixel LED strip and connect it to the Atmega328P.  
2. **Software Setup**: Install the FastLED library and upload the firmware to the microcontroller.  
3. **Power Supply**: Connect a 5V, 6.0A power supply for optimal performance.  

---

## **Future Scope**  
- Integration with IoT for remote control and updates.  
- Multi-language text display support.  
- Energy optimization for longer runtimes.  

---

## **License**  
This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.  

---

## **Author**  
Developed by **Omkar Ankush Kashid**.  

---

## **References**  
1. [FastLED Library Documentation](https://fastled.io/)  
2. Relevant IEEE Papers on LED matrix displays.  
