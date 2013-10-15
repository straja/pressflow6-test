== Summary ==

This module alters the behaviour of the CCK Content Copy module, specifically
the import procedure (admin/content/types/import). Therefore, this module
requires CCK Content Copy in order to be installed.

== What it actually does ==

The regular Content Copy module allows just two types of import:

    - import an entire content type as new content type
    - import new fields into an existing content type

This modules introduces a fully functional content type update procedure.
The import form has been altered in order for the UI to match the new
feature.

-- Import the entire content type --

When you choose "Import the entire content type", to different things can
happen, depending on the current status of your Drupal site.

If the content type you are about to import does not exist, this import will
work the same as per the regular Content Copy, importing the entire content
type as new content type into the system. On the contrary, if the content type
you want to import does actually exist, a full update will take place:

     - Content Type description and settings will be updated
     - New fields will be added
     - No longer existing fields will be dropped
     - Existing fields will be updated

In plain words, the content type will update so it will reflect its newly
imported defintion.

-- Import new fields into... --

This is just a new name for something that already exists. Basically, the list
of the existing content types has been grouped under the item
"Import only the fields into...", to make it clear to the user that when you
explicitly choose a pre-existing content type, only the fields will be taken
from the code pasted in the form, and only those fields that are new for the
selected content type will be actually imported.