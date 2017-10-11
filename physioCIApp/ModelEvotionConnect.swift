//
//  ModelEvotionConnect.swift
//  C3ConnectorProject
//
//  Created by Tine Meidahl Münsberg on 06/10/2017.
//  Copyright © 2017 Tine Meidahl Münsberg. All rights reserved.
//

import Foundation
import UIKit
import CoreBluetooth
import CoreData

class ModelEvotionConnect: NSObject, CBCentralManagerDelegate, CBPeripheralDelegate {
    
    var manager: CBCentralManager!
    var peripheral: CBPeripheral?
    var arrayEvotion: [NSManagedObject] = []

    let HearingAidName = "Tine"
    let ServiceUUID = CBUUID(string: "56772EAF-2153-4F74-ACF3-4368D99FBF5A")
    let CharacteristicUUID = CBUUID(string: "F8779BDF-06BA-487D-ADE9-EFE4F9A9A2F4")
    let CharacteristicUUID1 = CBUUID(string: "535442F7-0FF7-4FEC-9780-742F3EB00EDA")
    let CharacteristicUUID2 = CBUUID(string: "1454E9D6-F658-4190-8589-22AA9E3021EB")
    
    class var sharedInstance: ViewController { //make it singleton ??? WHY?
        struct Singleton {
            static let instance: ViewController = ViewController()
        }
        return Singleton.instance
    }
    
    public func centralManagerDidUpdateState(_ central: CBCentralManager) {
        //working
        if central.state == CBManagerState.poweredOn { //Check if the bluetooth is on
            print("Bluetooth is turned on")
            let connectedPeripherals = central.retrieveConnectedPeripherals(withServices:[ServiceUUID])// nessesary because Apples says so. If we want to keep looking
            print(connectedPeripherals)
            if (connectedPeripherals.count == 1){
                print(connectedPeripherals.count)
                central.stopScan()
                self.peripheral = connectedPeripherals.first!
                self.peripheral?.delegate = self
                central.connect(peripheral!, options: nil)
                print("hearing aid have been connected")
                print(peripheral!)
                peripheral?.discoverServices(nil)
            }
            //IS THE HEARING AID ALREADY CONNECTED??
        }
    }
    
    func centralManager(_ central: CBCentralManager, didFailToConnect peripheral: CBPeripheral, error: Error?) {
        print("**** CONNECTION TO SENSOR TAG FAILED!!!")
    }
    
    func centralManager(central: CBCentralManager, didConnectPeripheral peripheral: CBPeripheral){//Get list of services on that device - Not sure if it is necessary since I know which UUID need
        peripheral.discoverServices(nil)
        print("Peripheral UUID: \(peripheral.identifier.uuidString)")
    }
    func peripheral(_ peripheral: CBPeripheral, didDiscoverServices error: Error?) {
        print(peripheral)
        
        for service in peripheral.services!{
            let thisService = service as CBService // giver fejl XPC
            
            
            if service.uuid == ServiceUUID {
                peripheral.discoverCharacteristics(nil, for: thisService)
            }
        }
    }
    
    public func peripheral(_ peripheral: CBPeripheral, didDiscoverCharacteristicsFor service: CBService, error: Error?) {
        if let error = error {
            print("error: \(error)")
            return
        }
        for characteristic: CBCharacteristic in service.characteristics! {
            if characteristic.uuid == CharacteristicUUID{
                //Evotion data
                peripheral.setNotifyValue(true, for: characteristic)
            }
            if characteristic.uuid == CharacteristicUUID1{
                //The program have been changed to the following program
                peripheral.setNotifyValue(true, for: characteristic)
            }
            if characteristic.uuid == CharacteristicUUID2{
                //There have been a change in program
                peripheral.setNotifyValue(true, for: characteristic)
            }
            else if characteristic.uuid == CharacteristicUUID {
                peripheral.readValue(for: characteristic)
            }
        }
    }
    
    public func peripheral(_ peripheral: CBPeripheral, didUpdateValueFor characteristic: CBCharacteristic, error: Error?) {
        print(characteristic)
        let dataToSave = String(describing: characteristic)
        self.save(charateristic: dataToSave)
    }
    
    func save(charateristic: String) { //Save to core data
        guard let appDelegate = UIApplication.shared.delegate as? AppDelegate else{
            return
        }
        let managedContext = appDelegate.persistentContainer.viewContext
        let entity = NSEntityDescription.entity(forEntityName: "Evotion", in: managedContext)!
        let evotion = NSManagedObject(entity: entity, insertInto: managedContext)
        
        evotion.setValue(charateristic, forKey: "evotionData") //Setting evotion data in core data
        
        let date = NSDate();
        let formatter = DateFormatter();
        formatter.dateFormat = "yyyy-MM-dd HH:mm:ss ZZZ";
        let defaultTimeZoneStr = formatter.string(from: date as Date);
        evotion.setValue(defaultTimeZoneStr, forKey: "timestamp") // Setting timestamp in core data
        
        do {
            try managedContext.save()
            arrayEvotion.append(evotion)
            
            print("Evotion Database: \(evotion)")
            
        } catch let error as NSError {
            print("Could not save. \(error), \(error.userInfo)")
        }
    }
    
    func centralManager(_ central: CBCentralManager, didDisconnectPeripheral peripheral: CBPeripheral, error: Error?) {
        central.retrieveConnectedPeripherals(withServices:[ServiceUUID])// nessesary because Apples says so. If we want to keep looking
    }
    
    func startUpManager(){
        manager = CBCentralManager(delegate: self, queue: nil)
    }
    
}
