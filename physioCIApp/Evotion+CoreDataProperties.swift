//
//  Evotion+CoreDataProperties.swift
//  C3ConnectorProject
//
//  Created by Tine Meidahl Münsberg on 09/10/2017.
//  Copyright © 2017 Tine Meidahl Münsberg. All rights reserved.
//
//

import Foundation
import CoreData


extension Evotion {

    @nonobjc public class func fetchRequest() -> NSFetchRequest<Evotion> {
        return NSFetchRequest<Evotion>(entityName: "Evotion")
    }

    @NSManaged public var evotionData: String?
    @NSManaged public var timestamp: String?

}
