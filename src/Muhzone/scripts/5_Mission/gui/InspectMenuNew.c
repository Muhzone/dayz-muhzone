/**
 * Apparently, the UI needs to know about liquid types so it can render the inspection menu properly.
 *
 * This is definitely not right, but we have to deal with this mess somehow.
 */
modded class InspectMenuNew extends UIScriptedMenu
{
    /**
     * Overrides the inspection widget with the proper text and colors.
     *
     * Since static methods cannot access their parent class and BI apparently didn't think about
     * that, we cannot use "super" and have to duplicate the original script code (again) just to
     * add a new liquid name and color.
     *
     * This code will therefore break with every update which affects the original method.
     *
     * @param root_widget Root widget.
     * @param item        Inventory item.
     */
    override static void UpdateItemInfoLiquidType(Widget root_widget, EntityAI item)
    {
        // -------------------- BEGIN BI CODE --------------------
        if ( item.IsInherited( ZombieBase ) || item.IsInherited( Car ) ) return;

        ItemBase item_base = ItemBase.Cast( item );

        if( item_base && item_base.GetQuantity() > 0 && item_base.IsBloodContainer() )
        {
            BloodContainerBase blood_container = BloodContainerBase.Cast( item_base );

            if( blood_container.GetBloodTypeVisible() )
            {
                string type;
                bool positive;
                string blood_type_name = BloodTypes.GetBloodTypeName(blood_container.GetLiquidType(), type, positive);
                WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_blood: " + blood_type_name, Colors.COLOR_LIQUID);
            }
            else
            {
                WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_blood", Colors.COLOR_LIQUID);
            }
        }
        else if( item_base && item_base.GetQuantity() > 0 && item_base.IsLiquidContainer() )
        {
            int liquid_type = item_base.GetLiquidType();

            switch(liquid_type)
            {
                case LIQUID_WATER:
                {
                    WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_water", Colors.COLOR_LIQUID);
                    break;
                }

                case LIQUID_RIVERWATER:
                {
                    WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_river_water", Colors.COLOR_LIQUID);
                    break;
                }

                case LIQUID_VODKA:
                {
                    WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_vodka", Colors.COLOR_LIQUID);
                    break;
                }

                case LIQUID_BEER:
                {
                    WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_beer", Colors.COLOR_LIQUID);
                    break;
                }

                case LIQUID_GASOLINE:
                {
                    WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_gasoline", Colors.COLOR_LIQUID);
                    break;
                }

                case LIQUID_DIESEL:
                {
                    WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_diesel", Colors.COLOR_LIQUID);
                    break;
                }

                case LIQUID_DISINFECTANT:
                {
                    WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_disinfectant", Colors.COLOR_LIQUID);
                    break;
                }

                case LIQUID_SALINE:
                {
                    WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_saline", Colors.COLOR_LIQUID);
                    break;
                }
                // -------------------- END BI CODE --------------------

                // -------------------- BEGIN MUHZONE CODE --------------------
                case LIQUID_MILK:
                {
                    WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#muhzone_inventory_liquid_type_milk", Colors.COLOR_LIQUID_MILK);
                    break;
                }
                // -------------------- END MUHZONE CODE --------------------

                // -------------------- BEGIN BI CODE --------------------
                default:
                {
                    WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "ERROR", Colors.COLOR_LIQUID);
                    break;
                }
            }
        }
        else
        {
            WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "");
        }
        // -------------------- END BI CODE --------------------
    }
};